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
      bool should_move_dirs = false;
      std::string excluded_dirs[2] = {".", ".."};
      std::string album_name = (std::string)album->d_name;

      for(int i = 0; i <= 2; i++){
        if(album_name.compare(excluded_dirs[i]) == 0){
          should_move_dirs = true;
        }
      }
      if(!should_move_dirs){
        std::cout << album_name << "\n";
      }
    }
  }
  closedir(album_dir);

  return true;
}
