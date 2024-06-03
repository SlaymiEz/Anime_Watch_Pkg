cmake_minimum_required(VERSION 3.10)
project(anime_watch)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

add_executable(anime_watch src/main.c)

target_link_libraries(anime_watch ${CURSES_LIBRARIES})