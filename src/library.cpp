#include <boost/foreach.hpp>
#include <boost/regex.hpp>
#include "library.h"

using std::cout;
using namespace boost::filesystem;

std::vector<Album*> Library::build(){
  path current_dir = location_.c_str();
  boost::filesystem::directory_iterator iter(current_dir), eod;

  BOOST_FOREACH(path dir, std::make_pair(iter, eod)){
    if(exists(dir)) {
      if(is_directory(dir)) {
        if(!should_move_dirs(dir)) {
          std::string album_name = album_name_for_path(dir);
          std::cout << album_name << "\n";
          Album alb;
          alb.artist_ = album_name;
          entries_.push_back(&alb);
        } else {
          std::cout << "Skipping directory:" << dir << "\n";
        }
      }
    }
  }
}

bool Library::should_move_dirs(path dir) {
  bool         should_move = false;
  boost::regex matcher("(\\.|\\..|\\.\\w+.*)\\z");
  if(boost::regex_match(dir.filename().string(), matcher)){
    should_move = true;
  }
  return should_move;
}

std::string Library::album_name_for_path(path dir) {
  boost::regex matcher("/\\.*\\z");
  boost::cmatch what_matched;

  if(boost::regex_match(dir.filename().c_str(), what_matched, matcher)){
    std::cout << what_matched;
    return (std::string)what_matched[1];
  } else {
    return "";
  }
}