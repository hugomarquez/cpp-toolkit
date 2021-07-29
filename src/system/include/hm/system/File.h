#pragma once

/**
 * @file File.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Filesystem abstraction around boost/filesystem
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <string>
#include <fstream>
namespace hm {
  class File {
    public:
      static std::string base_path;

      File(std::string p);
      ~File();

      std::ios_base::openmode getMode(int m);
      void setMode(int m);

      std::string getPath();
      std::string getFileName();
      std::string getExtension();
      std::string getFileNameNoExtension();

    private:
      std::string filename;
      std::string relative_path;
      std::string ext;
      void setFileName();
      void setExtension();
  };
}
