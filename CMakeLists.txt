cmake_minimum_required (VERSION 2.6)
project (libco)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(co_test co_test1.c amd64.c)
target_link_libraries(co_test z rt pthread)

