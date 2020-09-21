cmake_minimum_required(VERSION 3.18.2)

project(main)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/main.c )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

include_directories(${SRC_DIR}  )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})


target_compile_features(main PRIVATE c_std_11) 
add_library(libraries STATIC 
 "${SRC_DIR}/NodeAVL.c" "${SRC_DIR}/NodeAVL.h"
 "${SRC_DIR}/Stack.c" "${SRC_DIR}/Stack.h"
 )
target_link_libraries(
  main
  PUBLIC 
  libraries
)
