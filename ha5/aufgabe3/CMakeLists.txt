project(ha5_aufgabe3)

add_library(lib_${PROJECT_NAME} src/dummyvectordata.cc src/myvector.cc src/myvectordata.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_library(lib_${PROJECT_NAME}_2 src/circle4.cc src/point4.cc)
target_include_directories(lib_${PROJECT_NAME}_2 PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME}_2)
