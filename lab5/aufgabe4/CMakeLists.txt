project(lab5_aufgabe4)

add_library(lib_${PROJECT_NAME} src/circle6.cc src/drawingobject2.cc src/onedimobject2.cc src/point6.cc src/polygon6.cc src/rectangle.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)
target_link_libraries(lib_${PROJECT_NAME} PUBLIC lib_ha3_aufgabe1)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
