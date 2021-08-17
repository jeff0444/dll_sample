#ifndef math_API_H_
#define math_API_H_

#include <memory>
#include "SVdef.h"

class SV_EXPORTS math_class
{
public:
    virtual void input_a(int value) = 0;
    virtual void get_a(int &i, int &j) = 0;
    virtual int get_a_i() const = 0;
    virtual void Add(int b) = 0;
    virtual void Subtraction(int b) = 0;
    virtual void Multiply(int b) = 0;
};

// math_class 以指標方式建立
SV_EXPORTS std::shared_ptr<math_class> createMathClass(int a);
SV_EXPORTS math_class* createMathClass_pointer(int a);

// ============  use LoadLibraryA()  =============================================

#define checkHandle(_handle) { if (!_handle) return -2; }
typedef void* type_math_handle;
SV_EXTERN_C SV_EXPORTS type_math_handle createMathClass_C(int value);
SV_EXTERN_C SV_EXPORTS int destroyMathClass_C(type_math_handle &handle);
SV_EXTERN_C SV_EXPORTS int input_a_C(type_math_handle handle, int value);
SV_EXTERN_C SV_EXPORTS int get_a_C(type_math_handle handle, int &i, int &j);
SV_EXTERN_C SV_EXPORTS int Add_C(type_math_handle handle, int b);
SV_EXTERN_C SV_EXPORTS int Subtraction_C(type_math_handle handle, int b);
SV_EXTERN_C SV_EXPORTS int Multiply_C(type_math_handle handle, int b);

#endif //math_API_H_