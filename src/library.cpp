#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

std::vector<std::string*> Library::build(){
  std::vector<std::string> album_list = possible_albums();
}

bool Library::should_move_dirs(std::string dir) {
  bool         should_move = false;
  boost::regex matcher(".*(\\/\\.[a-zA-Z+]+|\\/\\.|\\/\\\\.\\\\.).*");
  if(boost::regex_match(dir, matcher)){
    should_move = true;
  }
  return should_move;
}

std::vector<std::string> Library::possible_albums(){
  std::string fake_string;
  std::vector<std::string> fake_vector;

  for(boost::filesystem::directory_iterator end, dir(location_); dir != end; ++dir){
    std::string file_name = dir->path().string();

    if(!should_move_dirs(file_name) && is_directory(dir->path())) {
      for(boost::filesystem::recursive_directory_iterator end, nested_dir(file_name); nested_dir != end; ++nested_dir){
        boost::regex mp3_matcher(".*\\.mp3");
        std::string file_path = nested_dir->path().string();

        if(boost::regex_match(file_path, mp3_matcher)){
          std::cout << id3_tag_for_file(file_path) << "\n";
        }

      }
    }
  }

  fake_vector.push_back(fake_string);
  return fake_vector;
}

std::string Library::id3_tag_for_file(std::string path_to_file){
  std::string tags;
  std::ifstream file_stream(path_to_file);
  char* buffer = new char[128];

  if(file_stream){
    file_stream.seekg(-128, std::ios_base::end);
    file_stream.readsome(buffer, 128);
    file_stream.close();
    tags = buffer;
  }

  return tags;
}



