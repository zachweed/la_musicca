cmake_minimum_required (VERSION 2.6)

project (LaMusicca)
set (LaMusicca_VERSION_MINOR 0.1)

configure_file(
  "${PROJECT_SOURCE_DIR}/la_musicca_config.h.in"
  "${PROJECT_BINARY_DIR}/la_musicca_config.h"
)

include_directories("${PROJECT_SOURCE_DIR}/yaml_cpp")
add_subdirectory (YamlCpp)



add_library(YamlCpp yaml-cpp.cxx)
target_link_libraries (LaMusicca YamlCpp)
add_executable(LaMusicca la_musicca.cpp)
