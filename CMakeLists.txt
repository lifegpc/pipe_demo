cmake_minimum_required(VERSION 3.0)

project(pro1)

include(CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckSymbolExists)

CHECK_INCLUDE_FILES(stdio.h HAVE_STDIO_H)
CHECK_INCLUDE_FILES(stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES(string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES(unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILES(io.h HAVE_IO_H)
CHECK_INCLUDE_FILES(fcntl.h HAVE_FCNTL_H)
CHECK_INCLUDE_FILES(malloc.h HAVE_MALLOC_H)
check_function_exists(pipe HAVE_PIPE)
check_function_exists(_pipe HAVE__PIPE)
check_function_exists(read HAVE_READ)
check_function_exists(_read HAVE__READ)
check_function_exists(write HAVE_WRITE)
check_function_exists(_write HAVE__WRITE)
check_function_exists(close HAVE_CLOSE)
check_function_exists(_close HAVE__CLOSE)
check_symbol_exists(O_BINARY fcntl.h HAVE_DECL_O_BINARY)
check_symbol_exists(printf_s stdio.h HAVE_PRINTF_S)
add_definitions(-DCMAKE_CONFIG)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(
    "cmake_config.h.in"
    "cmake_config.h"
)

add_executable(Demo src/main.c)
