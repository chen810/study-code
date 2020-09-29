include_directories(${PROJECT_SOURCE_DIR}/libhello)

set(APP_SRC main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../build/bin)

add_executable(study_code ${APP_SRC})

target_link_libraries(study_code libhello)