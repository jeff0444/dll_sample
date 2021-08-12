set (THE_MODULE "Dll_2Layer_main")
set (Lib_project "Dll_2Layer_tool") # connect Dll_2Layer_tool.lib

# include header
INCLUDE_DIRECTORIES(../tool/include)

# output Dll_2Layer_main.exe
ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})




