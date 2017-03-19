#include "iostream"

#ifndef LA_MUSICCA_LIBRARY_H
#define LA_MUSICCA_LIBRARY_H

class Library {
  std::string contents_;
public:
  Library(char* library_path);
};

#endif // LA_MUSICCA_LIBRARY_H
