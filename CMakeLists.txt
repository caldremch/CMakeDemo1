cmake_minimum_required(VERSION 3.7)

project(demo)

#启动测试
enable_testing()


#测试程序释放能成功运行
add_test(test_run demo)

#测试帮助信息是否可以正常提示, 因为我们的测试运行时输出的是:Hello, World!4
#在测试运行的时候,也没有传入任何参数, 然后我们指定了要匹配的输出内容后, 如果
#输出的内容包含我们制定的内容, 那么就是测试成功
add_test (test_usage demo)
set_tests_properties (test_usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Hello, World!4")

# 添加一个测试程序, 参数为5 2, 执行这个测试程序, 如果测试输出中包含有 xxxxxx, 即算测试及成功
#add_test (test_5_2 demo 5 2)
#set_tests_properties (test_5_2
#        PROPERTIES PASS_REGULAR_EXPRESSION "xxxxxx")


#如果要测试更多的输入数据, 可以定义一个宏来简化这些测试
macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} demo ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)


do_test (1 1 "Hello")


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


