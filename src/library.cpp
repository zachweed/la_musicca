#include <boost/archive/text_iarchive.hpp>
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
        boost::filesystem::path possible_mp3(nested_dir->path());

        if(possible_mp3.extension() == ".mp3"){
          std::cout << id3_tag_for_file(possible_mp3) << "\n";
        }

      }
    }
  }

  fake_vector.push_back(fake_string);
  return fake_vector;
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



