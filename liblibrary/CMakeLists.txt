set(LIB_SRC leetcode_solution.cpp MyHashset.cpp MyHashMap.cpp  MyTree.cpp)

add_library(liblibrary ${LIB_SRC})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../build/lib)

set_target_properties(liblibrary PROPERTIES OUTPUT_NAME "mylibrary")
