project(ha3_aufgabe2)

add_library(lib_${PROJECT_NAME} src/customer.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
