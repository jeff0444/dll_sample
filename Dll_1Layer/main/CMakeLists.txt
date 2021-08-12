set (THE_MODULE "Dll_1Layer_main")
set (Lib_project "Dll_1Layer_math") # connect Dll_1Layer_math.lib

# include header
INCLUDE_DIRECTORIES(../math/include)

# output Dll_1Layer_main.exe
ADD_EXECUTABLE(${THE_MODULE} test.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})


# ===============================================================

set (THE_MODULE "Dll_1Layer_main_withoutLib")

# output Dll_1Layer_main_withoutLib.exe
ADD_EXECUTABLE(${THE_MODULE} test_withoutLib.cpp)
TARGET_LINK_LIBRARIES(${THE_MODULE} ${Lib_project})