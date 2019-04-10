project(lab1_aufgabe3)

add_executable(app_${PROJECT_NAME} src/main.cc)

target_compile_definitions(app_${PROJECT_NAME} PRIVATE -D USE_USER_CONIO)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_package(Curses REQUIRED)
    target_link_libraries(app_${PROJECT_NAME} ${CURSES_LIBRARIES})
    include_directories(${CURSES_INCLUDE_DIR})
endif()
