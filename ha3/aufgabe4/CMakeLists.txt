cmake_minimum_required(VERSION 2.8)

project(ha3_aufgabe4)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
