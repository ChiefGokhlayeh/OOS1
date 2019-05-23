project(lab4_aufgabe1)

add_library(lib_${PROJECT_NAME} src/book.cc src/date.cc src/dvd.cc src/lecturer.cc src/library.cc src/medium.cc src/person.cc src/student.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
