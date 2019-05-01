project(lab3_aufgabe4)

add_library(lib_${PROJECT_NAME} src/circle3.cc src/point3.cc src/polygon3.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
