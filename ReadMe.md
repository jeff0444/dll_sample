dll_sample
====

# How to build
open cmd

    cd <this project path>
    build_msvc.bat

output file path:

    out\Release


# How to run
open cmd

    cd <this project path>
    run.bat
----------------------------------------------------

# project informent

## Dll_1Layer
### Dll_1Layer_math.dll
Base dll file

### Dll_1Layer_main.exe
connect -> Dll_1Layer_math.dll
used file：
- Dll_1Layer\math\include\my_math.h 
- Dll_1Layer_math.lib
- Dll_1Layer_math.dll

### Dll_1Layer_main_withoutLib.exe
connect -> Dll_1Layer_math.dll
used file：
- Dll_1Layer_math.dll

----------------------------------------------------
## Dll_2Layer
### Dll_2Layer_tool.dll
this dll connect other dll
connect -> Dll_1Layer_math.dll
used file：
- Dll_1Layer\math\include\my_math.h 
- Dll_1Layer_math.lib
- Dll_1Layer_math.dll   

### Dll_2Layer_main.exe
connect -> Dll_2Layer_tool.dll
used file：
- Dll_2Layer\tool\include\tool_API.h 
- Dll_2Layer_tool.lib
- Dll_2Layer_tool.dll 

----------------------------------------------------
## Dll_class
### Dll_class_math.dll
Base dll file
### Dll_class_main.exe
connect -> Dll_class_math.dll
used file：
- Dll_class\math_class\include\my_math_API.hpp 
- Dll_class_math.lib
- Dll_class_math.dll 


