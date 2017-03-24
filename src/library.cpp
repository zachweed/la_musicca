#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

std::vector<std::string*> Library::build(){
  possible_albums_for_directory(location_);
}

bool Library::should_move_dirs(std::string dir) {
  bool         should_move = false;
  boost::regex matcher(".*(\\/\\.[a-zA-Z+]+|\\/\\.|\\/\\\\.\\\\.).*");
  if(boost::regex_match(dir, matcher)){
    should_move = true;
  }
  return should_move;
}

std::vector<std::string> Library::possible_albums_for_directory(std::string media_dir){
  std::string fake_string;
  std::vector<std::string> fake_vector;

  for(boost::filesystem::directory_iterator end, dir(media_dir); dir != end; ++dir){
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
  std::ifstream file_stream(path_to_file);
  std::vector<char> buffer(128);
  std::string tags;

  if(file_stream){
    file_stream.seekg(buffer.size(), std::ios_base::end);
    file_stream.read(&buffer[0], buffer.size());
    std::string tags(buffer.begin(), buffer.end());
  }
  return tags;
}



