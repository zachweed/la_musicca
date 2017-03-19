#include "library.h"
#include <string>
#include "iostream"

int main(int argc, char *argv[]) {
  if(argc != 2){
    std::cout << "\nUsage: la_musicca +media_directory_to_tag+";
    return 1;
  }

  std::string media_path(argv[1]);
  Library library (&media_path);
  library.build();
  return 0;
};
