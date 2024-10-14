cmake_minimum_required(VERSION 3.5)

project(justedit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)

add_subdirectory(src/justedit)
