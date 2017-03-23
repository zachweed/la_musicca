#include <vector>
#include <boost/filesystem.hpp>
#include "iostream"
#include "album.h"

#ifndef LA_MUSICCA_LIBRARY_H
#define LA_MUSICCA_LIBRARY_H

class Library {
public:
  Library(std::string* library_path){ location_ = *library_path; };
  std::vector<std::string*> build();
private:
  std::vector<std::string*> entries_;
  std::string location_;
  bool should_move_dirs(std::string dir_name);
};

#endif // LA_MUSICCA_LIBRARY_H
