#ifndef math_H_
#define math_H_

#include "my_math_API.hpp"

// 假設newNumber這個資料型態不能或無法讓其他人知道
struct newNumber{
    int i;
    int j;
};

class math_classImpl final : public math_class
{
private:
    newNumber a;
public:
    math_classImpl(int value);

    virtual void input_a(int value) override;
    virtual void get_a(int &i, int &j) override;
    virtual int get_a_i() const override;
    virtual void Add(int b) override;
    virtual void Subtraction(int b) override;
    virtual void Multiply(int b) override;
};

// math_class 以指標方式建立
std::shared_ptr<math_class> createMathClass(int a);
math_class* createMathClass_pointer(int a);

// ============  use LoadLibraryA()  =============================================
// SV_EXTERN_C SV_EXPORTS type_math_handle createMathClass_C(int value);
// SV_EXTERN_C SV_EXPORTS int destroyMathClass_C(type_math_handle &handle);
// SV_EXTERN_C SV_EXPORTS int input_a_C(type_math_handle handle, int value);
// SV_EXTERN_C SV_EXPORTS int get_a_C(type_math_handle handle, int &a);
// SV_EXTERN_C SV_EXPORTS int Add_C(type_math_handle handle, int b);
// SV_EXTERN_C SV_EXPORTS int Subtraction_C(type_math_handle handle, int b);
// SV_EXTERN_C SV_EXPORTS int Multiply_C(type_math_handle handle, int b);

#endif //math_H_