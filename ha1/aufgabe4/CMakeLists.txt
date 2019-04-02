cmake_minimum_required(VERSION 2.8)

project(ha1_aufgabe4)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Install-prefix was at default -> forcing it to the build-dir")
    message(STATUS "    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../_install)'")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/../_install" CACHE PATH "default install path" FORCE)
endif()

add_executable(ha1_aufgabe4_cxx src/buggy.cc)
add_executable(ha1_aufgabe4_c src/buggy.c)

install(TARGETS ha1_aufgabe4_cxx DESTINATION bin)
install(TARGETS ha1_aufgabe4_c DESTINATION bin)
