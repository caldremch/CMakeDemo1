cmake_minimum_required(VERSION 3.7)

project(demo)


#加入一个配置头文件, 用于处理 CMake 对源码的设置
#configure_file 命令用于加入一个配置头文件 config.h ，
#这个文件由 CMake 从 config.h.in 生成，通过这样的机制，
#将可以通过预定义一些参数和变量来控制代码的生成。

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

#是否使用自己的 MyMath 库
option(USER_MYMATH
        "User provide math implementation" ON
        )

#是否加入 MyMath 库
if(USER_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/calculate")
    add_subdirectory(calculate)
    set(EXTRA_LIBS ${EXTRA_LIBS} MyMath)
endif(USER_MYMATH)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

#add_subdirectory(calculate)

add_executable(demo ${SOURCE_FILES})

target_link_libraries(demo ${EXTRA_LIBS})


