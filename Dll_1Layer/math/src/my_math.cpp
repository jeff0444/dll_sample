#include "my_math.h"


int Add(int a, int b)
{
    return a+b;
}
int Subtraction(int a, int b)
{
    return a-b;
}
int Multiply(int a, int b)
{
    return a*b;
}
int Divided(int a, int b)
{
    return a/b;
}
int Squared(int a, int b)
{
    for (int i = 0; i < b-1; i++)
    {
        a*=a;
    }
    return a;
}



int math_class::Add(int a, int b)
{
    return a+b;
}
int math_class::Subtraction(int a, int b)
{
    return a-b;
}
int math_class::Multiply(int a, int b)
{
    return a*b;
}