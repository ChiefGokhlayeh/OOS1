cmake_minimum_required(VERSION 2.8)

project(ha2_aufgabe1)

add_library(lib_user_conio src/user_conio.cc)
target_include_directories(lib_user_conio PUBLIC inc)

add_library(lib_${PROJECT_NAME} src/labyrinth.cc src/position.cc)
target_include_directories(lib_${PROJECT_NAME} PRIVATE inc)
target_compile_definitions(lib_${PROJECT_NAME} PUBLIC -D USE_USER_CONIO)
target_link_libraries(lib_${PROJECT_NAME} lib_user_conio)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_package(Curses REQUIRED)
    target_link_libraries(lib_${PROJECT_NAME} ${CURSES_LIBRARIES})
    target_include_directories(lib_${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
endif()

add_executable(app_${PROJECT_NAME} src/main.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
