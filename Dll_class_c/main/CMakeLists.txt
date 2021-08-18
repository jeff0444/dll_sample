set (THE_MODULE "Dll_class_main_c")
set (Lib_project "Dll_class_math_c") #connect Dll_class_math_c.lib

# include header
INCLUDE_DIRECTORIES(../math_class/include)

# output Dll_class_main_c.exe
ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})

set (THE_MODULE "Dll_class_main_c_withoutLib")
# output Dll_class_main_c_withoutLib.exe
ADD_EXECUTABLE(${THE_MODULE} test_withoutLib.cpp)