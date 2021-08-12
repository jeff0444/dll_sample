
#include <stdio.h>

#include "my_math.h"

int main()
{
    int a = 10;
    int b = 20;

    int res = Add(a,b);
    printf("Add %d\n", res);

    res = Subtraction(a,b);
    printf("Subtraction %d\n", res);


    res = Multiply(a,b);
    printf("Multiply %d\n", res);

    math_class math_cls;
    res = math_cls.Add(a,b);
    printf("math_class Add %d\n", res);

    res = math_cls.Subtraction(a,b);
    printf("math_class Subtraction %d\n", res);
    
    res = math_cls.Multiply(a,b);
    printf("math_class Multiply %d\n", res);




    return 0;
}