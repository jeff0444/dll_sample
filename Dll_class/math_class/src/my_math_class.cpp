#include "my_math_class.h"

math_classImpl::math_classImpl(int value)
{
    input_a(value);
}
void math_classImpl::input_a(int value)
{
    a.i = value;
    a.j = value*10;
}
void math_classImpl::get_a(int &i, int &j)
{
    i = a.i;
    j = a.j;
}
int math_classImpl::get_a_i() const
{
    return a.i;
}
void math_classImpl::Add(int b)
{
    a.i+=b;
    a.j+=b;
}
void math_classImpl::Subtraction(int b)
{
    a.i-=b;
    a.j-=b;
}
void math_classImpl::Multiply(int b)
{
    a.i*=b;
    a.j*=b;
}

// math_class 以指標方式建立
std::shared_ptr<math_class> createMathClass(int a)
{
    return std::make_shared<math_classImpl>(a);
}
math_class* createMathClass_pointer(int a)
{
    return new math_classImpl(a);
}

// ============  use LoadLibraryA()  =============================================
SV_EXTERN_C SV_EXPORTS type_math_handle createMathClass_C(int value)
{
    return (type_math_handle)new math_classImpl(value);
}
SV_EXTERN_C SV_EXPORTS int destroyMathClass_C(type_math_handle &handle)
{
    checkHandle(handle);
    delete (math_classImpl *)handle;
    handle = NULL;
    return 0;
}
SV_EXTERN_C SV_EXPORTS int input_a_C(type_math_handle handle, int value)
{
    checkHandle(handle);
    math_classImpl *p_math_class = (math_classImpl *)handle;
    p_math_class->input_a(value);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int get_a_C(type_math_handle handle, int &i, int &j)
{
    i = 0;
    j = 0;
    checkHandle(handle);
    math_classImpl *p_math_class = (math_classImpl *)handle;
    p_math_class->get_a(i, j);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Add_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_classImpl *p_math_class = (math_classImpl *)handle;
    p_math_class->Add(b);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Subtraction_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_classImpl *p_math_class = (math_classImpl *)handle;
    p_math_class->Subtraction(b);
    return 0;
}
SV_EXTERN_C SV_EXPORTS int Multiply_C(type_math_handle handle, int b)
{
    checkHandle(handle);
    math_classImpl *p_math_class = (math_classImpl *)handle;
    p_math_class->Multiply(b);
    return 0;
}