cmake_minimum_required(VERSION 3.13)
project(datastruct)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES  "Src/*.*" "Inc/*.*" "Test/*.*")
add_executable(datastruct ${SOURCES} main.cpp Src/FileCache.cpp Inc/FileCache.h)
#set(CMAKE_EXE_LINKER_FLAGS -static)
