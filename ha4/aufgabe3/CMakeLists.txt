project(ha4_aufgabe3)

add_library(lib_${PROJECT_NAME} src/powerdrill.cc src/powerscrewdrill.cc src/powerscrewdriver.cc src/powertool.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
