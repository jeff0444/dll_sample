set (THE_MODULE "Dll_1Layer_main")

INCLUDE_DIRECTORIES(../math/include)

set(LIB_PATH ${CMAKE_SOURCE_DIR}/out/intel64/Release)
file(GLOB LIBS "${LIB_PATH}/*.lib")

ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${LIBS})


set (THE_MODULE "Dll_1Layer_main_withoutLib")
ADD_EXECUTABLE(${THE_MODULE} test_withoutLib.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${LIBS})