#include "iostream"

#ifndef LA_MUSICCA_LIBRARY_H
#define LA_MUSICCA_LIBRARY_H

class Library {
public:
  Library(std::string* library_path);
  bool build();
private:
  std::string location_;
  bool should_move_dirs(std::string dir_name);
};

#endif // LA_MUSICCA_LIBRARY_H
