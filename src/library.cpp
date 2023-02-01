#include <boost/archive/text_iarchive.hpp>
#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

std::vector<std::string*> Library::build(){
  possible_albums_for_directory(location_);
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

std::string Library::id3_tag_for_file(boost::filesystem::path path_to_file){
  int tag_size = 128;
  char tags[tag_size];
  boost::filesystem::ifstream file_stream(path_to_file);
  std::string fake_string;

  file_stream.seekg(-(tag_size), std::ios::end);
  file_stream.read(reinterpret_cast<char *>(&tags), tag_size);
  file_stream.close();

  printf(tags);

  return fake_string;
}



