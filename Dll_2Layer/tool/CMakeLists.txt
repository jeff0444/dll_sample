
set (THE_MODULE "Dll_2Layer_tool")
set (Lib_project "Dll_1Layer_math") # connect Dll_1Layer_math.lib

# include header
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/Dll_1Layer/math/include)
INCLUDE_DIRECTORIES(./include)

# output Dll_2Layer_tool.lib Dll_2Layer_tool.dll
ADD_LIBRARY(${THE_MODULE} SHARED src/tool_API.cpp)
target_compile_definitions(${THE_MODULE} PRIVATE EXPORT_API) # c++ define EXPORT_API
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})

