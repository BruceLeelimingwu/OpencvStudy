cmake_minimum_required(VERSION 3.6)
project(OpencvStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp salt-pepper.cpp readFromDir.cpp)
add_executable(OpencvStudy ${SOURCE_FILES})

find_package( OpenCV REQUIRED)
target_link_libraries( OpencvStudy ${OpenCV_LIBS})
