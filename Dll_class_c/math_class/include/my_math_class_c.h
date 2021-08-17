#ifndef my_math_H_
#define my_math_H_

#include "SVdef.h"

struct newNumber{
    int i;
    int j;
};

class SV_EXPORTS math_class
{
public:    
    newNumber a;
    math_class(int value);

    void input_a(int value);
    void get_a(newNumber &a_);
    void Add(int b);
    void Subtraction(int b);
    void Multiply(int b);
};

// ============  use LoadLibraryA()  =============================================

#define checkHandle(_handle) { if (!_handle) return -2; }
typedef void* type_math_handle;
SV_EXTERN_C SV_EXPORTS type_math_handle createMathClass_C(int a);
SV_EXTERN_C SV_EXPORTS int destroyMathClass_C(type_math_handle &handle);
SV_EXTERN_C SV_EXPORTS int input_a_C(type_math_handle handle, int value);
SV_EXTERN_C SV_EXPORTS int get_a_C(type_math_handle handle, int &i, int &j);
SV_EXTERN_C SV_EXPORTS int Add_C(type_math_handle handle, int b);
SV_EXTERN_C SV_EXPORTS int Subtraction_C(type_math_handle handle, int b);
SV_EXTERN_C SV_EXPORTS int Multiply_C(type_math_handle handle, int b);
#endif //my_math_H_