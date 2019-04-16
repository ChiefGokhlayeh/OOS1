project(lab2_aufgabe1)

add_executable(app_${PROJECT_NAME} src/main.cc src/pacman.cc src/player.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
target_link_libraries(app_${PROJECT_NAME} lib_ha2_aufgabe1)
target_link_libraries(app_${PROJECT_NAME} lib_ha2_aufgabe2)

target_compile_definitions(app_${PROJECT_NAME} PUBLIC -D USE_NCURSES)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_package(Curses REQUIRED)
    target_link_libraries(app_${PROJECT_NAME} ${CURSES_LIBRARIES})
    target_include_directories(app_${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
endif()
