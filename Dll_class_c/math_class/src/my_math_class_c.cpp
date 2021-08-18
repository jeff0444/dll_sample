#include <stdio.h>
#include "my_math_class_c.h"

math_class::math_class(int value)
{
    input_a(value);
}
void math_class::input_a(int value)
{
    a.i = value;
    a.j = value*10;
}
void math_class::get_a(newNumber &a_)
{
    a_ = a;
}

void math_class::Add(int b)
{
    a.i+=b;
    a.j+=b;
}
void math_class::Subtraction(int b)
{
    a.i-=b;
    a.j-=b;
}
void math_class::Multiply(int b)
{
    a.i*=b;
    a.j*=b;
}

// ============  use LoadLibraryA()  =============================================

SV_EXTERN_C SV_EXPORTS type_math_handle createMathClass_C(int a)
{
    return (type_math_handle)new math_class(a);
}
SV_EXTERN_C SV_EXPORTS int destroyMathClass_C(type_math_handle &handle)
{
    checkHandle(handle);
    delete (math_class *)handle;
    handle = NULL;
    return 0;
}
SV_EXTERN_C SV_EXPORTS int input_a_C(type_math_handle handle, int value)
{
    checkHandle(handle);
    math_class *p_math_class = (math_class *)handle;
    p_math_class->input_a(value);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int get_a_C(type_math_handle handle, int &i, int &j)
{
    i = j = 0;
    checkHandle(handle);
    math_class *p_math_class = (math_class *)handle;
    newNumber a;
    p_math_class->get_a(a);
    i = a.i;
    j = a.j;
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Add_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_class *p_math_class = (math_class *)handle;
    p_math_class->Add(b);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Subtraction_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_class *p_math_class = (math_class *)handle;
    p_math_class->Subtraction(b);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Multiply_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_class *p_math_class = (math_class *)handle;
    p_math_class->Multiply(b);
    return 0;
}