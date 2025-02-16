cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(voice_control C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(voice_control main.c)
target_link_libraries(voice_control pico_stdlib)
pico_add_extra_outputs(voice_control)
