# A CMake file for building the Wren (static) library.
cmake_minimum_required(VERSION 3.29)

project(wren LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(wren 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/wren.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/wren.hpp,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_common.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_compiler.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_core.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_debug.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_debugger.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_debugger_types.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_primitive.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_utils.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_value.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_vm.h,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_compiler.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_core.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_debug.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_debugger.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_primitive.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_utils.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_value.c,
    ${CMAKE_CURRENT_SOURCE_DIR}/src/wren_vm.c)

