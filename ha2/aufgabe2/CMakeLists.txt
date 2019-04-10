cmake_minimum_required(VERSION 2.8)

project(ha2_aufgabe2)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Install-prefix was at default -> forcing it to the build-dir")
    message(STATUS "    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../_install)'")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/../_install" CACHE PATH "default install path" FORCE)
endif()

add_executable(ha2_aufgabe2 src/mystring.cc src/main.cc)
target_include_directories(ha2_aufgabe2 PRIVATE inc)

install(TARGETS ha2_aufgabe2 DESTINATION bin)
