#include "library.h"
#include "iostream"

int main(int argc, char *argv[]) {
  if(argc != 2){
    std::cout << "\nUsage: la_musicca +media_directory_to_tag+";
    return 1;
  }

  char media_path = *argv[1];
  Library library (&media_path);
  return 0;
};
