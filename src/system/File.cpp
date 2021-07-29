#include "include/hm/system/File.h"

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

namespace hm {
  std::string File::base_path;
  fs::path path;
  
  File::File(std::string p) : relative_path(p) 
  {
    path = File::base_path + relative_path;
    setFileName();
    setExtension();
  }

  File::~File(){}

  std::string File::getPath(){ return path.string();}
  std::string File::getExtension(){ return ext;}
  std::string File::getFileName(){ return filename; }

  std::ios_base::openmode File::getMode(int m)
  {
    switch (m) {
    case 1: return std::fstream::app;   break;
    case 2: return std::fstream::ate;   break;
    case 3: return std::fstream::in;    break;
    case 4: return std::fstream::out;   break;
    case 5: return std::fstream::trunc; break;
    default: return std::fstream::in;   break;
    }
  }

  std::string File::getFileNameNoExtension()
  {
    return boost::filesystem::change_extension(filename, "").string();
  }

  void File::setFileName()
  {
    filename = path.has_filename() ? path.filename().string() : path.string();
  }

  void File::setExtension()
  {
    ext = path.has_extension() ? path.extension().string() : path.string();
  }
}
