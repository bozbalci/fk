cmake_minimum_required(VERSION 3.4.3)

project(fk)

find_program(LLVM_CONFIG "llvm-config")
if(LLVM_CONFIG)
    message(STATUS "Found LLVM_CONFIG as ${LLVM_CONFIG}")
    set(CONFIG_COMMAND ${LLVM_CONFIG}
        "--cxxflags"
        "--ldflags"
        "--system-libs"
        "--libs"
        "core"
        "mcjit"
        "native"
        "nativecodegen"
        "irreader"
        "linker")
    execute_process(
        COMMAND ${CONFIG_COMMAND}
        RESULT_VARIABLE HAD_ERROR
        OUTPUT_VARIABLE CONFIG_OUTPUT
    )
    if(NOT HAD_ERROR)
        string(REGEX REPLACE
            "[ \t]*[\r\n]+[ \t]*" " "
            CONFIG_OUTPUT ${CONFIG_OUTPUT})
    else()
        string(REPLACE ";" " " CONFIG_COMMAND_STR "${CONFIG_COMMAND}")
        message(STATUS "${CONFIG_COMMAND_STR}")
        message(FATAL_ERROR "llvm-config failed with status ${HAD_ERROR}")
    endif()
else()
    message(FATAL_ERROR "llvm-config not found -- ${LLVM_CONFIG}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CONFIG_OUTPUT}")
file(GLOB_RECURSE SOURCES src/*.cc)
add_executable(fk ${SOURCES})
