#ifndef math_H_
#define math_H_

#include "my_math_API.hpp"

class math_classImpl final : public math_class
{
private:
    int a;
public:
    math_classImpl(int value) { a = value; };

    virtual void input_a(int value) override { a = value; };
    virtual int get_a() const override { return a; };
    virtual int Add(int b) override;
    virtual int Subtraction(int b) override;
    virtual int Multiply(int b) override;
};

std::shared_ptr<math_class> createMathClass(int a);

#endif //math_H_