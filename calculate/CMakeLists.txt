cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIR_LIB_SERC)

#将${DIR_LIB_SERC}里面的源文件, 编译成静态库如libMyMath.a
add_library(MyMath ${DIR_LIB_SERC})