cmake_minimum_required(VERSION 3.16)
project(study_code)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src)

add_subdirectory(liblibrary)

#set(LIB_SRC leetcode_solution.cpp MyHashset.cpp MyHashMap.cpp  MyTree.cpp)

#set(APP_SRC main.cpp)

#add_library(hello ${LIB_SRC})

#add_executable(study_code ${APP_SRC})

#target_link_libraries(study_code hello)
#add_executable(study_code main.cpp leetcode_solution.cpp leetcode_solution.h MyHashset.cpp MyHashset.h MyHashMap.cpp MyHashMap.h MyTree.cpp MyTree.h)
