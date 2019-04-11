cmake_minimum_required(VERSION 3.13)
project(SimpleEncryter C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
add_executable(SimpleEncryter main.c src/encrypter.c)