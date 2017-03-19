#include <dirent.h>
#include "library.h"

Library::Library(char* library_path) {
  const char* PATH = library_path;
  DIR *starting_dir = opendir(PATH);
  struct dirent *album = readdir(starting_dir);

  printf("%s\n", album->d_name);

  while(album != NULL) {
    if (album->d_type == DT_DIR)
      // We need to recursively crawl the dir
      // structure, in order to build up a DB of tags.
    album = readdir(starting_dir);
  }
  closedir(starting_dir);
}
