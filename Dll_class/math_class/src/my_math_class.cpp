#include "my_math_class.h"



int math_classImpl::Add(int b)
{
    return a+=b;
}
int math_classImpl::Subtraction(int b)
{
    return a-=b;
}
int math_classImpl::Multiply(int b)
{
    return a*=b;
}

std::shared_ptr<math_class> createMathClass(int a)
{
    return std::make_shared<math_classImpl>(a);
}