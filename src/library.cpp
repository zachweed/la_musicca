#include <regex>
#include <dirent.h>
#include "library.h"

Library::Library(std::string* library_path) {
  location_ = *library_path;
}

bool Library::build() {
  DIR *album_dir;
  struct dirent *album;
  if( (album_dir = opendir(this->location_.c_str()) ) == NULL) {
    std::cout << "Error(" << errno << ") opening " << album_dir << std::endl;
  }

  while( (album = readdir(album_dir) ) != NULL) {
    if (album->d_type == DT_DIR) {
      std::string album_name = (std::string)album->d_name;
      if(!should_move_dirs(album_name)){
        std::cout << (std::string)album->d_name << "\n";
      }
    }
  }
  closedir(album_dir);

  return true;
}

bool Library::should_move_dirs(std::string dir_name) {
  bool        should_move_dirs = false;
  std::string excluded_like(".");
  std::string excluded_dirs[2] = {".", ".."};
  std::size_t excluded_found = dir_name.find(excluded_like);

  if(excluded_found != std::string::npos){
    should_move_dirs = true;
  }

  for(int i = 0; i <= 2; i++){
    if((dir_name.compare(excluded_dirs[i]) == 0)){
      should_move_dirs = true;
    }
  }
  return should_move_dirs;
}
