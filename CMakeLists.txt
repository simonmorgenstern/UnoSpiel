cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_C_STANDARD 11)

add_executable(src main.c main.h ende.c ende.h handkarten.c handkarten.h kartendeck.h kartendeck.c menue.c menue.h)