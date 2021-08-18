#include <stdio.h>
#include <windows.h>

struct My_math_dll
{
private:
    HMODULE hLib;
    bool enable = false;

public:
    // handle class 的 void pointer
    typedef void* type_math_handle;
    //定義每個 function 原始的樣子
    typedef type_math_handle(*createMathClass_C)(int a);
    typedef int(*destroyMathClass_C)(type_math_handle &handle);
    typedef int(*get_a_C)(type_math_handle handle, int &i, int &j);
    typedef int(*Add_C)(type_math_handle handle, int b);

    //宣告 function 在這邊使用時的名稱
    type_math_handle math_h = NULL;
    createMathClass_C createMathClass;
    destroyMathClass_C destroyMathClass;
    get_a_C get_a;
    Add_C Add;

    ~My_math_dll()
    {
        release();
    }

    int loadAPI()
    {
        // 讀入 dll
        hLib = LoadLibraryA("Dll_class_math_c.dll");
        
        // If the dll file fails, the memory address will be 0.
        printf_s("Dll_class_math_c.dll address:%p\n", hLib);
        if (!hLib)
        { 
            printf_s("load Dll_class_math_c.dll fail!\n");
            return 0;
        }

        // 將每個 function 的 address 讀入
        createMathClass = (createMathClass_C)GetProcAddress(hLib, "createMathClass_C");
        destroyMathClass = (destroyMathClass_C)GetProcAddress(hLib, "destroyMathClass_C");
        get_a = (get_a_C)GetProcAddress(hLib, "get_a_C");
        Add = (Add_C)GetProcAddress(hLib, "Add_C");

        // Check the memory address obtained by the function API.
        // If the function API fails, the memory address will be 0.
        printf_s("API address: %p %p\n", createMathClass, Add);
        enable = true;
        return 0;
    }

    void release()
    {
        if (enable)
        {
            destroyMathClass(math_h);  //刪除 class
            FreeLibrary(hLib);
            enable = false;
        }
    }
};

int main()
{
    int a = 10;
    int b = 20;
    int i,j;

    My_math_dll dll = My_math_dll();
    dll.loadAPI();
    dll.math_h = dll.createMathClass(a);

    dll.get_a(dll.math_h, i, j);
    printf("get_a_C %d %d\n", i, j);

    dll.Add(dll.math_h, b);
    dll.get_a(dll.math_h, i, j);
    printf("Add_C %d %d\n", i, j);

    dll.release();
    return 0;
}