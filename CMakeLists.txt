cmake_minimum_required(VERSION 3.11.4)

project(MeLibInternal CXX)

add_library(MeLibInternal INTERFACE)

target_include_directories(MeLibInternal INTERFACE inc)

target_compile_features(MeLibInternal INTERFACE cxx_std_17)





project(MeLibBench CXX)

find_package(benchmark REQUIRED)
include ("${PROJECT_SOURCE_DIR}/cmake/google_better_of.cmake")

add_executable(MeLibBench bench/MeLibBench)

target_link_libraries(MeLibBench PRIVATE MeLibInternal benchmark pthread)


add_custom_target(
    BenchResult ALL
    # BYPRODUCTS "${PROJECT_BINARY_DIR}/data.csv"
    COMMAND "message"
    "COUCOU $<TARGET_FILE:MeLibBench>"
    # COMMAND ${CMAKE_COMMAND}
    #   "-DTARGET_FILE=$<TARGET_FILE:MeLibBench>"
    #   "-DCONFIG_FILE_OUTPUT=${PROJECT_BINARY_DIR}/data.csv"
    #   "-P" "${CMAKE_CURRENT_LIST_DIR}/cmake/google_better_of.cmake"
    COMMENT "GENERATE DEPENDENCY ORDER"
    COMMAND_EXPAND_LISTS VERBATIM
)

add_dependencies(BenchResult MeLibBench)




# project(MeLib CXX)