
cmake_minimum_required(VERSION 3.9)

project(clocker VERSION 1.0 DESCRIPTION "Tool to help time things")
include(GNUInstallDirs)
include_directories(./inc)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY /usr/local/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /usr/local/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(clocker SHARED
    src/Clocker.cpp
    inc/Clocker.hpp
)

set_target_properties(clocker PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(clocker PROPERTIES PUBLIC_HEADER "inc/Clocker.hpp")

install(TARGETS clocker
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION /usr/local/include)

add_compile_options(-std=c++11)

set(CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(srcs
    ${CMAKE_SOURCE_DIR}/src/example.cpp
)


add_executable(example.x ${srcs})
target_link_libraries(example.x clocker)

