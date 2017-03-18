cmake_minimum_required(VERSION 2.8.9)
project (la_musicca)


file(GLOB INCLUDES "include/*.h")
file(GLOB SOURCES "src/*.cpp")
add_executable(la_musicca ${SOURCES} ${INCLUDES})

find_package(Boost 1.36.0 REQUIRED)
include_directories(include ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES ${SOURCES})
