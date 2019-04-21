project(ha3_aufgabe5)

add_library(lib_${PROJECT_NAME} src/vehicle.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)
target_link_libraries(lib_${PROJECT_NAME} lib_ha3_aufgabe3)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
