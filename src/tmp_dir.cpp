#include <miopen/tmp_dir.hpp>
#include <boost/filesystem.hpp>
#include <miopen/errors.hpp>

namespace miopen {

void SystemCmd(std::string cmd)
{
// std::cout << cmd << std::endl;
// We shouldn't call system commands
#ifdef MIOPEN_USE_CLANG_TIDY
    (void)cmd;
#else
    if(std::system(cmd.c_str()) != 0)
        MIOPEN_THROW("Can't execute " + cmd);
#endif
}

TmpDir::TmpDir(std::string prefix)
    : path(boost::filesystem::temp_directory_path() /
           boost::filesystem::unique_path("miopen-" + prefix + "-%%%%-%%%%-%%%%-%%%%"))
{
    boost::filesystem::create_directories(this->path);
}

void TmpDir::Execute(std::string exe, std::string args)
{
    std::string cd  = "cd " + this->path.string() + "; ";
    std::string cmd = cd + exe + " " + args; // + " > /dev/null";
    SystemCmd(cmd);
}

TmpDir::~TmpDir() { boost::filesystem::remove_all(this->path); }

} // namespace miopen
