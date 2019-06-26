project(lab5_aufgabe3)

add_library(lib_${PROJECT_NAME} src/mylist.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)
target_link_libraries(lib_${PROJECT_NAME} PUBLIC lib_ha5_aufgabe3_3)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
