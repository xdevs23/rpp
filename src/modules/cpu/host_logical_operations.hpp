#include <cpu/rpp_cpu_common.hpp>

/**************** bitwise_AND ***************/

template <typename T>
RppStatus bitwise_AND_host_batch(T* srcPtr1, T* srcPtr2, RppiSize *batch_srcSize, RppiSize *batch_srcSizeMax, T* dstPtr, 
                                 RppiROI *roiPoints, Rpp32u nbatchSize,
                                 RppiChnFormat chnFormat, Rpp32u channel)
{
    if(chnFormat == RPPI_CHN_PLANAR)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;

            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            for(int c = 0; c < channel; c++)
            {
                T *srcPtr1Channel, *srcPtr2Channel, *dstPtrChannel;
                srcPtr1Channel = srcPtr1Image + (c * imageDimMax);
                srcPtr2Channel = srcPtr2Image + (c * imageDimMax);
                dstPtrChannel = dstPtrImage + (c * imageDimMax);

                //#pragma omp parallel for simd
                #pragma omp parallel for
                for(int i = 0; i < batch_srcSize[batchCount].height; i++)
                {
                    Rpp8u pixel;

                    T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                    srcPtr1Temp = srcPtr1Channel + (i * batch_srcSizeMax[batchCount].width);
                    srcPtr2Temp = srcPtr2Channel + (i * batch_srcSizeMax[batchCount].width);
                    dstPtrTemp = dstPtrChannel + (i * batch_srcSizeMax[batchCount].width);
                    
                    if (!((y1 <= i) && (i <= y2)))
                    {
                        memcpy(dstPtrTemp, srcPtr1Temp, batch_srcSize[batchCount].width * sizeof(T));

                        srcPtr1Temp += batch_srcSizeMax[batchCount].width;
                        srcPtr2Temp += batch_srcSizeMax[batchCount].width;
                        dstPtrTemp += batch_srcSizeMax[batchCount].width;
                    }
                    else
                    {
                        for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                        {
                            if((x1 <= j) && (j <= x2 ))
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) & ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                            else
                            {
                                *dstPtrTemp = *srcPtr1Temp;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (chnFormat == RPPI_CHN_PACKED)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;
            
            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            Rpp32u elementsInRow = channel * batch_srcSize[batchCount].width;
            Rpp32u elementsInRowMax = channel * batch_srcSizeMax[batchCount].width;
            
            //#pragma omp parallel for simd
                #pragma omp parallel for
            for(int i = 0; i < batch_srcSize[batchCount].height; i++)
            {
                Rpp8u pixel;

                T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                srcPtr1Temp = srcPtr1Image + (i * elementsInRowMax);
                srcPtr2Temp = srcPtr2Image + (i * elementsInRowMax);
                dstPtrTemp = dstPtrImage + (i * elementsInRowMax);

                if (!((y1 <= i) && (i <= y2)))
                {
                    memcpy(dstPtrTemp, srcPtr1Temp, elementsInRow * sizeof(T));

                    srcPtr1Temp += elementsInRowMax;
                    srcPtr2Temp += elementsInRowMax;
                    dstPtrTemp += elementsInRowMax;
                }
                else
                {
                    for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                    {
                        if (!((x1 <= j) && (j <= x2 )))
                        {
                            memcpy(dstPtrTemp, srcPtr1Temp, channel * sizeof(T));

                            srcPtr1Temp += channel;
                            srcPtr2Temp += channel;
                            dstPtrTemp += channel;
                        }
                        else
                        {
                            for(int c = 0; c < channel; c++)
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) & ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return RPP_SUCCESS;
}

template <typename T, typename U>
RppStatus bitwise_AND_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
                           RppiChnFormat chnFormat, Rpp32u channel)
{
    compute_bitwise_AND_host(srcPtr1, srcPtr2, srcSize, dstPtr, channel);

    return RPP_SUCCESS;

}

/**************** bitwise_NOT ***************/

template <typename T>
RppStatus bitwise_NOT_host_batch(T* srcPtr, RppiSize *batch_srcSize, RppiSize *batch_srcSizeMax, T* dstPtr, 
                                 RppiROI *roiPoints, Rpp32u nbatchSize,
                                 RppiChnFormat chnFormat, Rpp32u channel)
{
    if(chnFormat == RPPI_CHN_PLANAR)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;

            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtrImage, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtrImage = srcPtr + loc;
            dstPtrImage = dstPtr + loc;

            for(int c = 0; c < channel; c++)
            {
                T *srcPtrChannel, *dstPtrChannel;
                srcPtrChannel = srcPtrImage + (c * imageDimMax);
                dstPtrChannel = dstPtrImage + (c * imageDimMax);

                //#pragma omp parallel for simd
                #pragma omp parallel for
                for(int i = 0; i < batch_srcSize[batchCount].height; i++)
                {
                    Rpp8u pixel;
                    
                    T *srcPtrTemp, *dstPtrTemp;
                    srcPtrTemp = srcPtrChannel + (i * batch_srcSizeMax[batchCount].width);
                    dstPtrTemp = dstPtrChannel + (i * batch_srcSizeMax[batchCount].width);
                    
                    if (!((y1 <= i) && (i <= y2)))
                    {
                        memcpy(dstPtrTemp, srcPtrTemp, batch_srcSize[batchCount].width * sizeof(T));

                        dstPtrTemp += batch_srcSizeMax[batchCount].width;
                        srcPtrTemp += batch_srcSizeMax[batchCount].width;
                    }
                    else
                    {
                        for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                        {
                            if((x1 <= j) && (j <= x2 ))
                            {
                                pixel = ~((Rpp8u) (*srcPtrTemp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtrTemp++;
                                dstPtrTemp++;
                            }
                            else
                            {
                                *dstPtrTemp = *srcPtrTemp;

                                srcPtrTemp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (chnFormat == RPPI_CHN_PACKED)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;
            
            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtrImage, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtrImage = srcPtr + loc;
            dstPtrImage = dstPtr + loc;

            Rpp32u elementsInRow = channel * batch_srcSize[batchCount].width;
            Rpp32u elementsInRowMax = channel * batch_srcSizeMax[batchCount].width;
            
            //#pragma omp parallel for simd
                #pragma omp parallel for
            for(int i = 0; i < batch_srcSize[batchCount].height; i++)
            {
                Rpp8u pixel;

                T *srcPtrTemp, *dstPtrTemp;
                srcPtrTemp = srcPtrImage + (i * elementsInRowMax);
                dstPtrTemp = dstPtrImage + (i * elementsInRowMax);

                if (!((y1 <= i) && (i <= y2)))
                {
                    memcpy(dstPtrTemp, srcPtrTemp, elementsInRow * sizeof(T));

                    dstPtrTemp += elementsInRowMax;
                    srcPtrTemp += elementsInRowMax;
                }
                else
                {
                    for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                    {
                        if (!((x1 <= j) && (j <= x2 )))
                        {
                            memcpy(dstPtrTemp, srcPtrTemp, channel * sizeof(T));

                            dstPtrTemp += channel;
                            srcPtrTemp += channel;
                        }
                        else
                        {
                            for(int c = 0; c < channel; c++)
                            {
                                pixel = ~((Rpp8u) (*srcPtrTemp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtrTemp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return RPP_SUCCESS;
}

template <typename T>
RppStatus bitwise_NOT_host(T* srcPtr, RppiSize srcSize, T* dstPtr,
                           RppiChnFormat chnFormat, Rpp32u channel)
{
    T *srcPtrTemp, *dstPtrTemp;
    srcPtrTemp = srcPtr;
    dstPtrTemp = dstPtr;

    Rpp8u pixel;

    for (int i = 0; i < (channel * srcSize.height * srcSize.width); i++)
    {
        pixel = ~((Rpp8u) (*srcPtrTemp));
        pixel = RPPPIXELCHECK(pixel);
        *dstPtrTemp =(T) pixel;
        srcPtrTemp++;
        dstPtrTemp++;
    }

    return RPP_SUCCESS;

}

/**************** exclusive_OR ***************/

template <typename T>
RppStatus exclusive_OR_host_batch(T* srcPtr1, T* srcPtr2, RppiSize *batch_srcSize, RppiSize *batch_srcSizeMax, T* dstPtr, 
                                 RppiROI *roiPoints, Rpp32u nbatchSize,
                                 RppiChnFormat chnFormat, Rpp32u channel)
{
    if(chnFormat == RPPI_CHN_PLANAR)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;

            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            for(int c = 0; c < channel; c++)
            {
                T *srcPtr1Channel, *srcPtr2Channel, *dstPtrChannel;
                srcPtr1Channel = srcPtr1Image + (c * imageDimMax);
                srcPtr2Channel = srcPtr2Image + (c * imageDimMax);
                dstPtrChannel = dstPtrImage + (c * imageDimMax);

                //#pragma omp parallel for simd
                #pragma omp parallel for
                for(int i = 0; i < batch_srcSize[batchCount].height; i++)
                {
                    Rpp8u pixel;

                    T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                    srcPtr1Temp = srcPtr1Channel + (i * batch_srcSizeMax[batchCount].width);
                    srcPtr2Temp = srcPtr2Channel + (i * batch_srcSizeMax[batchCount].width);
                    dstPtrTemp = dstPtrChannel + (i * batch_srcSizeMax[batchCount].width);
                    
                    if (!((y1 <= i) && (i <= y2)))
                    {
                        memcpy(dstPtrTemp, srcPtr1Temp, batch_srcSize[batchCount].width * sizeof(T));

                        srcPtr1Temp += batch_srcSizeMax[batchCount].width;
                        srcPtr2Temp += batch_srcSizeMax[batchCount].width;
                        dstPtrTemp += batch_srcSizeMax[batchCount].width;
                    }
                    else
                    {
                        for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                        {
                            if((x1 <= j) && (j <= x2 ))
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) ^ ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                            else
                            {
                                *dstPtrTemp = *srcPtr1Temp;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (chnFormat == RPPI_CHN_PACKED)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;
            
            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            Rpp32u elementsInRow = channel * batch_srcSize[batchCount].width;
            Rpp32u elementsInRowMax = channel * batch_srcSizeMax[batchCount].width;
            
            //#pragma omp parallel for simd
                #pragma omp parallel for
            for(int i = 0; i < batch_srcSize[batchCount].height; i++)
            {
                Rpp8u pixel;

                T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                srcPtr1Temp = srcPtr1Image + (i * elementsInRowMax);
                srcPtr2Temp = srcPtr2Image + (i * elementsInRowMax);
                dstPtrTemp = dstPtrImage + (i * elementsInRowMax);

                if (!((y1 <= i) && (i <= y2)))
                {
                    memcpy(dstPtrTemp, srcPtr1Temp, elementsInRow * sizeof(T));

                    srcPtr1Temp += elementsInRowMax;
                    srcPtr2Temp += elementsInRowMax;
                    dstPtrTemp += elementsInRowMax;
                }
                else
                {
                    for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                    {
                        if (!((x1 <= j) && (j <= x2 )))
                        {
                            memcpy(dstPtrTemp, srcPtr1Temp, channel * sizeof(T));

                            srcPtr1Temp += channel;
                            srcPtr2Temp += channel;
                            dstPtrTemp += channel;
                        }
                        else
                        {
                            for(int c = 0; c < channel; c++)
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) ^ ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return RPP_SUCCESS;
}

template <typename T, typename U>
RppStatus exclusive_OR_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
                            RppiChnFormat chnFormat, Rpp32u channel)
{
    compute_exclusive_OR_host(srcPtr1, srcPtr2, srcSize, dstPtr, channel);

    return RPP_SUCCESS;

}

/**************** inclusive_OR ***************/

template <typename T>
RppStatus inclusive_OR_host_batch(T* srcPtr1, T* srcPtr2, RppiSize *batch_srcSize, RppiSize *batch_srcSizeMax, T* dstPtr, 
                                 RppiROI *roiPoints, Rpp32u nbatchSize,
                                 RppiChnFormat chnFormat, Rpp32u channel)
{
    if(chnFormat == RPPI_CHN_PLANAR)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;

            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            for(int c = 0; c < channel; c++)
            {
                T *srcPtr1Channel, *srcPtr2Channel, *dstPtrChannel;
                srcPtr1Channel = srcPtr1Image + (c * imageDimMax);
                srcPtr2Channel = srcPtr2Image + (c * imageDimMax);
                dstPtrChannel = dstPtrImage + (c * imageDimMax);

                //#pragma omp parallel for simd
                #pragma omp parallel for
                for(int i = 0; i < batch_srcSize[batchCount].height; i++)
                {
                    Rpp8u pixel;

                    T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                    srcPtr1Temp = srcPtr1Channel + (i * batch_srcSizeMax[batchCount].width);
                    srcPtr2Temp = srcPtr2Channel + (i * batch_srcSizeMax[batchCount].width);
                    dstPtrTemp = dstPtrChannel + (i * batch_srcSizeMax[batchCount].width);
                    
                    if (!((y1 <= i) && (i <= y2)))
                    {
                        memcpy(dstPtrTemp, srcPtr1Temp, batch_srcSize[batchCount].width * sizeof(T));

                        srcPtr1Temp += batch_srcSizeMax[batchCount].width;
                        srcPtr2Temp += batch_srcSizeMax[batchCount].width;
                        dstPtrTemp += batch_srcSizeMax[batchCount].width;
                    }
                    else
                    {
                        for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                        {
                            if((x1 <= j) && (j <= x2 ))
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) | ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                            else
                            {
                                *dstPtrTemp = *srcPtr1Temp;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (chnFormat == RPPI_CHN_PACKED)
    {
        #pragma omp parallel for
        for(int batchCount = 0; batchCount < nbatchSize; batchCount ++)
        {
            Rpp32u imageDimMax = batch_srcSizeMax[batchCount].height * batch_srcSizeMax[batchCount].width;
            
            Rpp32f x1 = roiPoints[batchCount].x;
            Rpp32f y1 = roiPoints[batchCount].y;
            Rpp32f x2 = x1 + roiPoints[batchCount].roiWidth - 1;
            Rpp32f y2 = y1 + roiPoints[batchCount].roiHeight - 1;
            if (x2 == -1)
            {
                x2 = batch_srcSize[batchCount].width - 1;
                roiPoints[batchCount].roiWidth = batch_srcSize[batchCount].width;
            }
            if (y2 == -1)
            {
                y2 = batch_srcSize[batchCount].height - 1;
                roiPoints[batchCount].roiHeight = batch_srcSize[batchCount].height;
            }

            T *srcPtr1Image, *srcPtr2Image, *dstPtrImage;
            Rpp32u loc = 0;
            compute_image_location_host(batch_srcSizeMax, batchCount, &loc, channel);
            srcPtr1Image = srcPtr1 + loc;
            srcPtr2Image = srcPtr2 + loc;
            dstPtrImage = dstPtr + loc;

            Rpp32u elementsInRow = channel * batch_srcSize[batchCount].width;
            Rpp32u elementsInRowMax = channel * batch_srcSizeMax[batchCount].width;
            
            //#pragma omp parallel for simd
                #pragma omp parallel for
            for(int i = 0; i < batch_srcSize[batchCount].height; i++)
            {
                Rpp8u pixel;

                T *srcPtr1Temp, *srcPtr2Temp, *dstPtrTemp;
                srcPtr1Temp = srcPtr1Image + (i * elementsInRowMax);
                srcPtr2Temp = srcPtr2Image + (i * elementsInRowMax);
                dstPtrTemp = dstPtrImage + (i * elementsInRowMax);

                if (!((y1 <= i) && (i <= y2)))
                {
                    memcpy(dstPtrTemp, srcPtr1Temp, elementsInRow * sizeof(T));

                    srcPtr1Temp += elementsInRowMax;
                    srcPtr2Temp += elementsInRowMax;
                    dstPtrTemp += elementsInRowMax;
                }
                else
                {
                    for(int j = 0; j < batch_srcSize[batchCount].width; j++)
                    {
                        if (!((x1 <= j) && (j <= x2 )))
                        {
                            memcpy(dstPtrTemp, srcPtr1Temp, channel * sizeof(T));

                            srcPtr1Temp += channel;
                            srcPtr2Temp += channel;
                            dstPtrTemp += channel;
                        }
                        else
                        {
                            for(int c = 0; c < channel; c++)
                            {
                                pixel = ((Rpp8u) (*srcPtr1Temp)) | ((Rpp8u) (*srcPtr2Temp));
                                pixel = RPPPIXELCHECK(pixel);
                                *dstPtrTemp =(T) pixel;

                                srcPtr1Temp++;
                                srcPtr2Temp++;
                                dstPtrTemp++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return RPP_SUCCESS;
}

template <typename T, typename U>
RppStatus inclusive_OR_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
                            RppiChnFormat chnFormat, Rpp32u channel)
{
    compute_inclusive_OR_host(srcPtr1, srcPtr2, srcSize, dstPtr, channel);

    return RPP_SUCCESS;

}

// /**************** Bitwise And ***************/

// template <typename T, typename U>
// RppStatus bitwise_AND_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
//                            RppiChnFormat chnFormat, Rpp32u channel)
// {
//     T *srcPtr1Temp, *dstPtrTemp;
//     U *srcPtr2Temp;
//     srcPtr1Temp = srcPtr1;
//     srcPtr2Temp = srcPtr2;
//     dstPtrTemp = dstPtr;

//     Rpp8u pixel;

//     for (int i = 0; i < (channel * srcSize.height * srcSize.width); i++)
//     {
//         pixel = ((Rpp8u) (*srcPtr1Temp)) & ((Rpp8u) (*srcPtr2Temp));
//         pixel = RPPPIXELCHECK(pixel);
//         *dstPtrTemp =(T) pixel;
//         srcPtr1Temp++;
//         srcPtr2Temp++;
//         dstPtrTemp++;
//     }

//     return RPP_SUCCESS;

// }

// /**************** Bitwise Not ***************/

// template <typename T>
// RppStatus bitwise_NOT_host(T* srcPtr, RppiSize srcSize, T* dstPtr,
//                            RppiChnFormat chnFormat, Rpp32u channel)
// {
//     T *srcPtrTemp, *dstPtrTemp;
//     srcPtrTemp = srcPtr;
//     dstPtrTemp = dstPtr;

//     Rpp8u pixel;

//     for (int i = 0; i < (channel * srcSize.height * srcSize.width); i++)
//     {
//         pixel = ~((Rpp8u) (*srcPtrTemp));
//         pixel = RPPPIXELCHECK(pixel);
//         *dstPtrTemp =(T) pixel;
//         srcPtrTemp++;
//         dstPtrTemp++;
//     }

//     return RPP_SUCCESS;

// }

// /**************** Bitwise Exclusive Or ***************/

// template <typename T, typename U>
// RppStatus exclusive_OR_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
//                             RppiChnFormat chnFormat, Rpp32u channel)
// {
//     T *srcPtr1Temp, *dstPtrTemp;
//     U *srcPtr2Temp;
//     srcPtr1Temp = srcPtr1;
//     srcPtr2Temp = srcPtr2;
//     dstPtrTemp = dstPtr;

//     Rpp8u pixel;

//     for (int i = 0; i < (channel * srcSize.height * srcSize.width); i++)
//     {
//         pixel = ((Rpp8u) (*srcPtr1Temp)) ^ ((Rpp8u) (*srcPtr2Temp));
//         pixel = RPPPIXELCHECK(pixel);
//         *dstPtrTemp =(T) pixel;
//         srcPtr1Temp++;
//         srcPtr2Temp++;
//         dstPtrTemp++;
//     }

//     return RPP_SUCCESS;

// }

// /**************** Bitwise Inclusive Or ***************/

// template <typename T, typename U>
// RppStatus inclusive_OR_host(T* srcPtr1, U* srcPtr2, RppiSize srcSize, T* dstPtr,
//                             RppiChnFormat chnFormat, Rpp32u channel)
// {
//     T *srcPtr1Temp, *dstPtrTemp;
//     U *srcPtr2Temp;
//     srcPtr1Temp = srcPtr1;
//     srcPtr2Temp = srcPtr2;
//     dstPtrTemp = dstPtr;

//     Rpp8u pixel;

//     for (int i = 0; i < (channel * srcSize.height * srcSize.width); i++)
//     {
//         pixel = ((Rpp8u) (*srcPtr1Temp)) | ((Rpp8u) (*srcPtr2Temp));
//         pixel = RPPPIXELCHECK(pixel);
//         *dstPtrTemp =(T) pixel;
//         srcPtr1Temp++;
//         srcPtr2Temp++;
//         dstPtrTemp++;
//     }

//     return RPP_SUCCESS;

// }