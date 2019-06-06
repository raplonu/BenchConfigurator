cmake_minimum_required(VERSION 3.11.4)

project(MeLib CXX)

add_library(MeLibInternal INTERFACE)

target_include_directories(MeLibInternal INTERFACE inc_internal)

target_compile_features(MeLibInternal INTERFACE cxx_std_17)







find_package(benchmark REQUIRED)

add_executable(MeLibBench bench/MeLibBench.cpp)

target_link_libraries(MeLibBench PRIVATE MeLibInternal benchmark pthread)

add_custom_target(
    BenchResult ALL
    BYPRODUCTS "${PROJECT_BINARY_DIR}/inc/config.hpp"
    COMMAND ${CMAKE_COMMAND}
      "-DEXECUTABLE=${PROJECT_BINARY_DIR}/MeLibBench"
      "-DINFILE=${PROJECT_SOURCE_DIR}/inc/config.hpp.in"
      "-DOUTFILE=${PROJECT_BINARY_DIR}/inc/config.hpp"
      "-P" "${PROJECT_SOURCE_DIR}/cmake/google_better_of.cmake"
    COMMENT "GENERATE DEPENDENCY ORDER"
    COMMAND_EXPAND_LISTS VERBATIM
)

add_dependencies(BenchResult MeLibBench)





add_library(MeLib SHARED src/MeLib.cpp)

target_include_directories(MeLib PRIVATE inc ${CMAKE_BINARY_DIR}/inc)

target_link_libraries(MeLib PRIVATE MeLibInternal)

add_dependencies(MeLib BenchResult)
