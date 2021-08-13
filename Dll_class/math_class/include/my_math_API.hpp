#ifndef math_API_H_
#define math_API_H_

#include <memory>
#include "SVdef.h"

class SV_EXPORTS math_class
{
public:
    virtual void input_a(int value) = 0;
    virtual int get_a() const = 0;
    virtual int Add(int b) = 0;
    virtual int Subtraction(int b) = 0;
    virtual int Multiply(int b) = 0;
};

SV_EXPORTS std::shared_ptr<math_class> createMathClass(int a);

#endif //math_API_H_