project(ha5_aufgabe3)

add_library(lib_${PROJECT_NAME}_1 src/myvector.cc)
target_include_directories(lib_${PROJECT_NAME}_1 PUBLIC inc)

add_library(lib_${PROJECT_NAME}_2 src/dummydata.cc src/mydata.cc)
target_include_directories(lib_${PROJECT_NAME}_2 PUBLIC inc)

add_library(lib_${PROJECT_NAME}_3 src/circle4.cc src/point4.cc)
target_include_directories(lib_${PROJECT_NAME}_3 PUBLIC inc)
target_link_libraries(lib_${PROJECT_NAME}_3 PUBLIC lib_${PROJECT_NAME}_2)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME}_1)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME}_3)
