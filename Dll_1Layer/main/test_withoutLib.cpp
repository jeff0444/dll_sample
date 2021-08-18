
#include <stdio.h>
#include <windows.h>

struct My_math_dll
{
private:
    HMODULE hLib;
    bool enable = false;

public:
    //定義每個 function 原始的樣子
    typedef int(*Add)(int a, int b);
    typedef int(*Subtraction)(int a, int b);
    typedef int(*Multiply)(int a, int b);
    typedef int(*Divided)(int a, int b);
    typedef int(*Squared)(int a, int b);

    //宣告 function 在這邊使用時的名稱
    Add add;
    Subtraction subtraction;
    Multiply multiply;
    Divided divided;
    Squared squared;

    ~My_math_dll()
    {
        release();
    }

    int loadAPI()
    {
        // 讀入 dll
        hLib = LoadLibraryA("Dll_1Layer_math.dll");
        
        // If the dll file fails, the memory address will be 0.
        printf_s("Dll_1Layer_math.dll address:%p\n", hLib);
        if (!hLib)
        { 
            printf_s("load Dll_1Layer_math.dll fail!\n");
            return 0;
        }

        // 將每個 function 的 address 讀入
        add = (Add)GetProcAddress(hLib, "Add");
        subtraction = (Subtraction)GetProcAddress(hLib, "Subtraction");
        multiply = (Multiply)GetProcAddress(hLib, "Multiply");
        divided = (Divided)GetProcAddress(hLib, "Divided");
        squared = (Squared)GetProcAddress(hLib, "Squared");

        // Check the memory address obtained by the function API.
        // If the function API fails, the memory address will be 0.
        printf_s("API address: %p %p\n", add, subtraction);
        enable = true;
        return 0;
    }

    void release()
    {
        if (enable)
        {
            FreeLibrary(hLib);
            enable = false;
        }
    }
};



int main()
{
    My_math_dll mydll;

    mydll.loadAPI();

    int a = 10;
    int b = 20;

    int res = mydll.add(a,b);
    printf("Add %d\n", res);

    res = mydll.subtraction(a,b);
    printf("Subtraction %d\n", res);

    res = mydll.multiply(a,b);
    printf("Multiply %d\n", res);

    mydll.release();

    return 0;
}