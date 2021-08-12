set (THE_MODULE "Dll_class_main")
set (Lib_project "Dll_class_math") #connect Dll_class_math.lib

# include header
INCLUDE_DIRECTORIES(../math_class/include)

# output Dll_class_main.exe
ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})
