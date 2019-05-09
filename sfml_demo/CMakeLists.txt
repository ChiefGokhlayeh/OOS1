project(sfml_demo)

add_executable(app_${PROJECT_NAME} src/main.cc)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.4.2 REQUIRED network audio graphics window system)
target_include_directories(app_${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(app_${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

find_package(OpenGL REQUIRED)
target_include_directories(app_${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(app_${PROJECT_NAME} ${OPENGL_LIBRARIES})
