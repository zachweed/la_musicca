#include <vector>
#include <boost/filesystem.hpp>
#include "iostream"
#include "album.h"

#ifndef LA_MUSICCA_LIBRARY_H
#define LA_MUSICCA_LIBRARY_H

class Library {
public:
  Library(std::string* library_path){ location_ = *library_path; };
  std::vector<Album*> build();
private:
  std::vector<Album*> entries_;
  std::string location_;
  bool should_move_dirs(boost::filesystem::path dir_name);
  std::string album_name_for_path(boost::filesystem::path dir);
};

#endif // LA_MUSICCA_LIBRARY_H
