# A CMake file for building the Wren (static) library.
cmake_minimum_required(VERSION 3.29)

project(wren LANGUAGES C)

set(CMAKE_CXX_STANDARD 20)

add_library(wren STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/include/wren.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/wren.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_compiler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_debug.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_debugger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_debugger_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_primitive.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_utils.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_value.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_vm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/optional/wren_opt_random.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/optional/wren_opt_meta.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_compiler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_debug.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_debugger.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_primitive.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_utils.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_value.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/wren_vm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/optional/wren_opt_meta.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/optional/wren_opt_random.c)

target_include_directories(wren
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/vm
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/include
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/optional)

