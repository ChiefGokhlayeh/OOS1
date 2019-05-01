project(lab3_aufgabe3)

add_library(lib_${PROJECT_NAME} src/circle2.cc src/point2.cc src/polygon2.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
