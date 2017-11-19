#include <miopen/binary_cache.hpp>
#include <miopen/md5.hpp>
#include <miopen/errors.hpp>
#include <miopen/env.hpp>
#include <miopen/stringutils.hpp>
#include <miopen/miopen.h>
#include <miopen/version.h>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

namespace miopen {

MIOPEN_DECLARE_ENV_VAR(MIOPEN_DISABLE_CACHE)

boost::filesystem::path ComputeCachePath()
{
#ifdef MIOPEN_CACHE_DIR
    std::string cache_dir = MIOPEN_CACHE_DIR;

    std::string version = std::to_string(MIOPEN_VERSION_MAJOR) + "." +
                          std::to_string(MIOPEN_VERSION_MINOR) + "." +
                          std::to_string(MIOPEN_VERSION_PATCH);
    auto p =
        boost::filesystem::path{miopen::ReplaceString(cache_dir, "~", getenv("HOME"))} / version;
    if(!boost::filesystem::exists(p))
        boost::filesystem::create_directories(p);
    return p;
#else
    return {};
#endif
}

boost::filesystem::path GetCachePath()
{
    static const boost::filesystem::path path = ComputeCachePath();
    return path;
}

bool IsCacheDisabled()
{
#ifdef MIOPEN_CACHE_DIR
    return miopen::IsDisabled(MIOPEN_DISABLE_CACHE{});
#else
    return true;
#endif
}

boost::filesystem::path GetCacheFile(const std::string& device,
                                     const std::string& name,
                                     const std::string& args,
                                     bool is_kernel_str)
{
    std::string filename = (is_kernel_str ? miopen::md5(name) : name) + ".o";
    return GetCachePath() / miopen::md5(device + ":" + args) / filename;
}

std::string LoadBinary(const std::string& device,
                       const std::string& name,
                       const std::string& args,
                       bool is_kernel_str)
{
    if(miopen::IsCacheDisabled())
        return {};
    auto f = GetCacheFile(device, name, args, is_kernel_str);
    if(boost::filesystem::exists(f))
    {
        return f.string();
    }
    else
    {
        return {};
    }
}
void SaveBinary(const boost::filesystem::path& binary_path,
                const std::string& device,
                const std::string& name,
                const std::string& args,
                bool is_kernel_str)
{
    if(miopen::IsCacheDisabled())
    {
        boost::filesystem::remove(binary_path);
    }
    else
    {
        auto p = GetCacheFile(device, name, args, is_kernel_str);
        boost::filesystem::create_directories(p.parent_path());
        boost::filesystem::rename(binary_path, p);
    }
}

} // namespace miopen
