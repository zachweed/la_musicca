#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

Library::Library(std::string* library_path) {
  location_ = *library_path;
}

std::vector<std::string> Library::build(){
  path current_dir = location_.c_str();
  boost::filesystem::directory_iterator iter(current_dir), eod;

  BOOST_FOREACH(path dir, std::make_pair(iter, eod)){
    if (exists(dir)) {
      if (is_directory(dir)) {
        if(!should_move_dirs(dir.filename().string())) {
          std::cout << dir << "\n";
          entries_.push_back(dir.string());
        } else {
          std::cout << "Skipping directory:" << dir << "\n";
        }
      }
    }
  }
}

bool Library::should_move_dirs(std::string dir_name) {
  bool         should_move = false;
  boost::regex matcher("(\\.|\\..|\\.\\w+.*)\\z");
  if(boost::regex_match(dir_name, matcher)){
    should_move = true;
  }
  return should_move;
}
