project(ha1_aufgabe2)

add_executable(app_${PROJECT_NAME}_c src/main.c)
add_executable(app_${PROJECT_NAME}_cc src/main.cc)

target_link_libraries(app_${PROJECT_NAME}_c m)
