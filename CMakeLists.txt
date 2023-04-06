cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.21)

project(spidercam VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(main src/main.cpp src/io/io.cpp src/kamera/kamera.cpp src/spielfeld/spielfeld.cpp)

file(COPY data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY_FILE data/input.dat ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data/input.dat)
