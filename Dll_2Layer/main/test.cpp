
#include <stdio.h>
#include "tool_API.h"


int main()
{
    int a = 10;
    int b = 20;

    int res = tool_Add(a,b);
    printf("tool_Add %d\n", res);

    res = tool_Subtraction(a,b);
    printf("tool_Subtraction %d\n", res);


    res = tool_Multiply(a,b);
    printf("tool_Multiply %d\n", res);

    return 0;
}