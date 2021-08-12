
set (THE_MODULE "Dll_class_math")

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/common)
INCLUDE_DIRECTORIES(./include)

ADD_LIBRARY(${THE_MODULE} SHARED src/my_math_class.cpp)
target_compile_definitions(${THE_MODULE} PRIVATE EXPORT_API)