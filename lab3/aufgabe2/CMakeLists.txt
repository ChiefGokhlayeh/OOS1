project(lab3_aufgabe2)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
target_link_libraries(app_${PROJECT_NAME} lib_ha3_aufgabe3)
