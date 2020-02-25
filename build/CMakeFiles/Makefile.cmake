# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# The generator used is:
set(CMAKE_DEPENDS_GENERATOR "Unix Makefiles")

# The top level Makefile was generated from the following files:
set(CMAKE_MAKEFILE_DEPENDS
  "CMakeCache.txt"
  "../CMakeLists.txt"
  "../addkernels/CMakeLists.txt"
  "CMakeFiles/3.16.4/CMakeCCompiler.cmake"
  "CMakeFiles/3.16.4/CMakeCXXCompiler.cmake"
  "CMakeFiles/3.16.4/CMakeSystem.cmake"
  "../cmake/Analyzers.cmake"
  "../cmake/ClangTidy.cmake"
  "../cmake/CppCheck.cmake"
  "../cmake/FindOpenCL.cmake"
  "../src/modules/CMakeLists.txt"
  "../src/modules/cl/CMakeLists.txt"
  "../src/modules/cl/kernel/absolute_difference.cl"
  "../src/modules/cl/kernel/accumulate.cl"
  "../src/modules/cl/kernel/add.cl"
  "../src/modules/cl/kernel/bilateral_filter.cl"
  "../src/modules/cl/kernel/bitwise_AND.cl"
  "../src/modules/cl/kernel/bitwise_NOT.cl"
  "../src/modules/cl/kernel/blend.cl"
  "../src/modules/cl/kernel/box_filter.cl"
  "../src/modules/cl/kernel/brightness_contrast.cl"
  "../src/modules/cl/kernel/canny_edge_detector.cl"
  "../src/modules/cl/kernel/channel_combine.cl"
  "../src/modules/cl/kernel/channel_extract.cl"
  "../src/modules/cl/kernel/color_temperature.cl"
  "../src/modules/cl/kernel/colortwist.cl"
  "../src/modules/cl/kernel/contrast.cl"
  "../src/modules/cl/kernel/convert_bit_depth.cl"
  "../src/modules/cl/kernel/convolution.cl"
  "../src/modules/cl/kernel/crop_mirror_normalize.cl"
  "../src/modules/cl/kernel/custom_convolution.cl"
  "../src/modules/cl/kernel/dilate.cl"
  "../src/modules/cl/kernel/dummy.cl"
  "../src/modules/cl/kernel/erode.cl"
  "../src/modules/cl/kernel/exclusive_OR.cl"
  "../src/modules/cl/kernel/exposure.cl"
  "../src/modules/cl/kernel/fast_corner_detector.cl"
  "../src/modules/cl/kernel/fish_eye.cl"
  "../src/modules/cl/kernel/flip.cl"
  "../src/modules/cl/kernel/fog.cl"
  "../src/modules/cl/kernel/gamma_correction.cl"
  "../src/modules/cl/kernel/gaussian_filter.cl"
  "../src/modules/cl/kernel/gaussian_image_pyramid.cl"
  "../src/modules/cl/kernel/harris_corner_detector.cl"
  "../src/modules/cl/kernel/hist.cl"
  "../src/modules/cl/kernel/histogram.cl"
  "../src/modules/cl/kernel/hsv_kernels.cl"
  "../src/modules/cl/kernel/hue.cl"
  "../src/modules/cl/kernel/inclusive_OR.cl"
  "../src/modules/cl/kernel/integral.cl"
  "../src/modules/cl/kernel/jitter.cl"
  "../src/modules/cl/kernel/laplacian_image_pyramid.cl"
  "../src/modules/cl/kernel/lens_correction.cl"
  "../src/modules/cl/kernel/local_binary_pattern.cl"
  "../src/modules/cl/kernel/look_up_table.cl"
  "../src/modules/cl/kernel/magnitude.cl"
  "../src/modules/cl/kernel/match_template.cl"
  "../src/modules/cl/kernel/max.cl"
  "../src/modules/cl/kernel/mean_stddev.cl"
  "../src/modules/cl/kernel/median_filter.cl"
  "../src/modules/cl/kernel/min.cl"
  "../src/modules/cl/kernel/min_max.cl"
  "../src/modules/cl/kernel/multiply.cl"
  "../src/modules/cl/kernel/noise.cl"
  "../src/modules/cl/kernel/non_max_suppression.cl"
  "../src/modules/cl/kernel/occlusion.cl"
  "../src/modules/cl/kernel/phase.cl"
  "../src/modules/cl/kernel/pixelate.cl"
  "../src/modules/cl/kernel/rain.cl"
  "../src/modules/cl/kernel/random_shadow.cl"
  "../src/modules/cl/kernel/reconstruction_laplacian_image_pyramid.cl"
  "../src/modules/cl/kernel/remap.cl"
  "../src/modules/cl/kernel/resize.cl"
  "../src/modules/cl/kernel/rotate.cl"
  "../src/modules/cl/kernel/scale.cl"
  "../src/modules/cl/kernel/scan.cl"
  "../src/modules/cl/kernel/snow.cl"
  "../src/modules/cl/kernel/sobel.cl"
  "../src/modules/cl/kernel/subtract.cl"
  "../src/modules/cl/kernel/temperature.cl"
  "../src/modules/cl/kernel/tensor.cl"
  "../src/modules/cl/kernel/thresholding.cl"
  "../src/modules/cl/kernel/vignette.cl"
  "../src/modules/cl/kernel/warp_affine.cl"
  "../src/modules/cl/kernel/warp_perspective.cl"
  "../src/modules/kernels/kernel.cpp.in"
  "../src/modules/kernels/kernel_includes.cpp.in"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeCInformation.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeCXXInformation.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeCheckCompilerFlagCommonPatterns.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeCommonLanguageInclude.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeGenericSystem.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeInitializeConfigs.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeLanguageInformation.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeParseArguments.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeParseImplicitLinkInfo.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeSystemSpecificInformation.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CMakeSystemSpecificInitialize.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CheckCXXCompilerFlag.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/CheckCXXSourceCompiles.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Compiler/CMakeCommonCompilerMacros.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Compiler/GNU-C.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Compiler/GNU-CXX.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Compiler/GNU.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/FindBoost.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/FindOpenMP.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/FindPackageHandleStandardArgs.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/FindPackageMessage.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Internal/CMakeCheckCompilerFlag.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Platform/Linux-GNU-C.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Platform/Linux-GNU-CXX.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Platform/Linux-GNU.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Platform/Linux.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/Platform/UnixPaths.cmake"
  "/snap/cmake/252/share/cmake-3.16/Modules/ProcessorCount.cmake"
  )

# The corresponding makefile is:
set(CMAKE_MAKEFILE_OUTPUTS
  "Makefile"
  "CMakeFiles/cmake.check_cache"
  )

# Byproducts of CMake generate step:
set(CMAKE_MAKEFILE_PRODUCTS
  "CMakeFiles/CMakeDirectoryInformation.cmake"
  "src/modules/CMakeFiles/CMakeDirectoryInformation.cmake"
  "src/modules/cl/CMakeFiles/CMakeDirectoryInformation.cmake"
  "addkernels/CMakeFiles/CMakeDirectoryInformation.cmake"
  )

# Dependency information for all targets:
set(CMAKE_DEPEND_INFO_FILES
  "CMakeFiles/amd_rpp.dir/DependInfo.cmake"
  "CMakeFiles/tidy.dir/DependInfo.cmake"
  "CMakeFiles/analyze.dir/DependInfo.cmake"
  "CMakeFiles/tidy-base.dir/DependInfo.cmake"
  "CMakeFiles/tidy-make-fixit-dir.dir/DependInfo.cmake"
  "CMakeFiles/cppcheck.dir/DependInfo.cmake"
  "CMakeFiles/tidy-rm-fixit-dir.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_build_src_modules_kernel_includes_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_color_model_conversions_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_fused_functions_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_logger_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_md5_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_binary_cache_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/rpp_tidy_inlining.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_geometry_transforms_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/modules.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_utilities_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_arithmetic_operations_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_kernel_cache_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_computer_vision_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_logical_operations_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_filter_operations_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_image_augmentations_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_build_src_modules_kernel_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_morphological_operations_cpp.dir/DependInfo.cmake"
  "src/modules/CMakeFiles/tidy-target-modules-_home_mvx_git_AMDRPP_src_modules_rppi_statistical_operations_cpp.dir/DependInfo.cmake"
  "src/modules/cl/CMakeFiles/modules-opencl.dir/DependInfo.cmake"
  "addkernels/CMakeFiles/addkernels.dir/DependInfo.cmake"
  )
