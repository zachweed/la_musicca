cmake_minimum_required(VERSION 2.8.9)
project (la_musicca)


file(GLOB INCLUDES "include/*.h")
file(GLOB SOURCES "src/*.cpp")
add_executable(la_musicca ${SOURCES} ${INCLUDES})

find_package(Boost 1.61.0 COMPONENTS filesystem regex)
include_directories(include ${Boost_INCLUDE_DIRS})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(la_musicca ${Boost_LIBRARIES})
endif()

set(SOURCE_FILES ${SOURCES})
