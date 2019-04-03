cmake_minimum_required(VERSION 2.8)

project(lab1_aufgabe3)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Install-prefix was at default -> forcing it to the build-dir")
    message(STATUS "    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../_install)'")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/../_install" CACHE PATH "default install path" FORCE)
endif()

add_executable(lab1_aufgabe3 src/main.cc)

add_definitions(-D USE_USER_CONIO)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_package(Curses REQUIRED)
    target_link_libraries(lab1_aufgabe3 ${CURSES_LIBRARIES})
    include_directories(${CURSES_INCLUDE_DIR})
endif()

install(TARGETS lab1_aufgabe3 DESTINATION bin)
