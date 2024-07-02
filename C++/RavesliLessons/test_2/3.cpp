#include <iostream>

double getDouble();
char getOperator();
void printResult(const double lhs, const char op, const double rhs);
 
int main()
{
    const double a = getDouble(), b = getDouble();
    const char op = getOperator();
    printResult(a, op, b);
    return 0;
}

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x;
    std::cin >> x;
    return x;
}
 
char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or / ";
    char op;
    std::cin >> op;
    return op;
}
 
void printResult(double lhs, char op, double rhs)
{
    std::cout << lhs << ' ' << op << ' ' << rhs << " = ";
    if(op == '+')
        std::cout << lhs + rhs;
    else if(op == '-')
        std::cout << lhs - rhs;
    else if(op == '*')
        std::cout << lhs * rhs;
    else if(op == '/' && rhs != 0)
        std::cout << lhs / rhs;
    std::cout << std::endl;
}