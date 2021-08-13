#ifndef math_H_
#define math_H_

#include "SVdef.h"

SV_EXTERN_C SV_EXPORTS int Add(int a, int b);
SV_EXTERN_C SV_EXPORTS int Subtraction(int a, int b);
SV_EXTERN_C SV_EXPORTS int Multiply(int a, int b);
SV_EXTERN_C SV_EXPORTS int Divided(int a, int b);
SV_EXTERN_C SV_EXPORTS int Squared(int a, int b);


class SV_EXPORTS math_class
{
public:
    int Add(int a, int b);
    int Subtraction(int a, int b);
    int Multiply(int a, int b);
};


#endif //math_H_