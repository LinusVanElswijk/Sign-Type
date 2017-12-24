cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES sign_test.cpp)

add_executable(SignTest ${SOURCE_FILES})
target_link_libraries(SignTest lc_sign catch)