
set (THE_MODULE "Dll_2Layer_tool")

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/Dll_1Layer/math/include)
INCLUDE_DIRECTORIES(./include)

set(LIB_PATH ${CMAKE_SOURCE_DIR}/out/intel64/Release)
file(GLOB LIBS "${LIB_PATH}/*.lib")

ADD_LIBRARY(${THE_MODULE} SHARED src/tool_API.cpp)
target_compile_definitions(${THE_MODULE} PRIVATE EXPORT_API)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${LIBS})

