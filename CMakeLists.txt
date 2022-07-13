cmake_minimum_required(VERSION 3.18)
project(26_2)

set(CMAKE_CXX_STANDARD 14)


add_executable(26_2 main.cpp include/contact.h include/phone.h src/contact.cpp src/phone.cpp)
