cmake_minimum_required(VERSION 3.5)
project(feedme C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES src/feedme.c includes/feedme.h)
add_executable(feedme ${SOURCE_FILES})

target_link_libraries(feedme ${GTK3_LIBRARIES})