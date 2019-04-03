cmake_minimum_required(VERSION 2.8)

project(lab1_aufgabe5)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Install-prefix was at default -> forcing it to the build-dir")
    message(STATUS "    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../_install)'")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/../_install" CACHE PATH "default install path" FORCE)
endif()

add_executable(lab1_aufgabe5 src/main.cc)

install(TARGETS lab1_aufgabe5 DESTINATION bin)
