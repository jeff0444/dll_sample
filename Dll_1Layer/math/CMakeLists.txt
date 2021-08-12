
set (THE_MODULE "Dll_1Layer_math")

# include header
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/common)
INCLUDE_DIRECTORIES(./include)

# output Dll_1Layer_math.lib Dll_1Layer_math.dll
ADD_LIBRARY(${THE_MODULE} SHARED src/my_math.cpp)
target_compile_definitions(${THE_MODULE} PRIVATE EXPORT_API) # c++ define EXPORT_API