set (THE_MODULE "Dll_class_main")

INCLUDE_DIRECTORIES(../math_class/include)

set(LIB_PATH ${CMAKE_SOURCE_DIR}/out/intel64/Release)
file(GLOB LIBS "${LIB_PATH}/*.lib")

ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${LIBS})
