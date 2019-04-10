project(lab2_aufgabe3)

add_library(lib_${PROJECT_NAME} src/circle.cc src/point.cc src/polygon.cc)
target_include_directories(lib_${PROJECT_NAME} PRIVATE inc)
target_include_directories(lib_${PROJECT_NAME} INTERFACE inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
