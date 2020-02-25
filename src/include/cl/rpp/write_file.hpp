#ifndef GUARD_MLOPEN_WRITE_FILE_HPP
#define GUARD_MLOPEN_WRITE_FILE_HPP

#include <boost/filesystem.hpp>
#include <rpp/manage_ptr.hpp>
#include <fstream>

namespace rpp {

using FilePtr = RPP_MANAGE_PTR(FILE*, std::fclose);

inline void WriteFile(const std::string& content, const boost::filesystem::path& name)
{
    // std::cerr << "Write file: " << name << std::endl;
    FilePtr f{std::fopen(name.string().c_str(), "w")};
    if(std::fwrite(content.c_str(), 1, content.size(), f.get()) != content.size())
        RPP_THROW("Failed to write to src file");
}
} // namespace rpp

#endif
