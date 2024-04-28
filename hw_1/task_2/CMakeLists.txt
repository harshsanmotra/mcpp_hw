cmake_minimum_required(VERSION 3.10)
project(task_2)

# set install folder
# make DESTDIR=/install/directory install
# set(CMAKE_INSTALL_PREFIX <path> CACHE PATH <comment> FORCE)
set(CMAKE_INSTALL_PREFIX install/)

set(CMAKE_CXX_STANDARD 17)
#  generate compiple commands file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# include(cmake/StaticAnalyzers.cmake)
set(CMAKE_CXX_FLAGS "-Wall")

## SET FOLDER
# set headers folder
#  c++ -I
include_directories(include/)
include_directories(include/ipb_arithmetic/)


# set libs folder
# c++ -L
link_directories()
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/results/lib)
# set executables folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/results/bin)

set(CMAKE_C_CLANG_TIDY
        clang-tidy;
            -header-filter=.*;
            -checks=*,-llvmlibc-restrict-system-libc-headers;
            -warnings-as-errors=*;)

## COMPILATION
add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)
add_executable(task_2_output src/main.cpp)
target_link_libraries(task_2_output ipb_arithmetic)

## INSTALL
# https://cmake.org/cmake/help/v3.10/command/install.html#
# Installing Files
# install(TARGETS myExe mySharedLib myStaticLib
#         RUNTIME DESTINATION bin
#         LIBRARY DESTINATION lib
#         ARCHIVE DESTINATION lib/static)
install(TARGETS ipb_arithmetic DESTINATION ${PROJECT_SOURCE_DIR}/install/lib)
# Installing Directories
install(DIRECTORY include/ DESTINATION ${PROJECT_SOURCE_DIR}/install/include/)