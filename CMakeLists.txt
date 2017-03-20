cmake_minimum_required(VERSION 2.8.9)
project (la_musicca)


file(GLOB INCLUDES "include/*.h")
file(GLOB SOURCES "src/*.cpp")
add_executable(la_musicca ${SOURCES} ${INCLUDES})

include_directories(include)

set(SOURCE_FILES ${SOURCES})
