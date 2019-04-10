cmake_minimum_required(VERSION 2.8)

project(ha2_aufgabe1)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Install-prefix was at default -> forcing it to the build-dir")
    message(STATUS "    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../_install)'")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/../_install" CACHE PATH "default install path" FORCE)
endif()

add_executable(ha2_aufgabe1 src/labyrinth.cc src/position.cc src/main.cc)
target_include_directories(ha2_aufgabe1 PRIVATE inc)

add_definitions(-D USE_USER_CONIO)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_package(Curses REQUIRED)
    target_link_libraries(ha2_aufgabe1 ${CURSES_LIBRARIES})
    target_include_directories(ha2_aufgabe1 PRIVATE ${CURSES_INCLUDE_DIR})
endif()

install(TARGETS ha2_aufgabe1 DESTINATION bin)
