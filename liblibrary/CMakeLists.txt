set(LIB_SRC my_base_structs.cpp my_base_structs.h)

add_library(liblibrary ${LIB_SRC})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

set_target_properties(liblibrary PROPERTIES OUTPUT_NAME "mylibrary")
