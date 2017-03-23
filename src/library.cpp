#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

std::vector<std::string*> Library::build(){
  for(boost::filesystem::directory_iterator end, dir(location_); dir != end; ++dir){
    std::string file_name = dir->path().string();

    if(!should_move_dirs(file_name) && is_directory(dir->path())) {
      for(boost::filesystem::recursive_directory_iterator end, nested_dir(file_name); nested_dir != end; ++nested_dir){
        std::cout << nested_dir->path().string() << "\n";
      }
    }
  }
}

bool Library::should_move_dirs(std::string dir) {
  bool         should_move = false;
  boost::regex matcher(".*(\\/\\.[a-zA-Z+]+|\\/\\.|\\/\\\\.\\\\.).*");
  if(boost::regex_match(dir, matcher)){
    should_move = true;
  }
  return should_move;
}