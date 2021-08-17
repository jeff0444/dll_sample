set (THE_MODULE "Dll_class_math_c")

# include header
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/common)
INCLUDE_DIRECTORIES(./include)

# output Dll_class_math_c.lib Dll_class_math_c.dll
ADD_LIBRARY(${THE_MODULE} SHARED src/my_math_class_c.cpp)
target_compile_definitions(${THE_MODULE} PRIVATE EXPORT_API) # c++ define EXPORT_API