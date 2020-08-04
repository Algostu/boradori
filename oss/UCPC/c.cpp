#include <iostream>
#include <string>
#include <cmath>

// 2
// a==b?a:0
//
// 10
// 0

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore(256, '\n');

    std::string expression;
    std::getline(std::cin, expression);


    int answer = 0;
    if (expression.size() == 1)
    {
        int value = expression[0] - '0';
        if (value == 0)
        {
            answer = pow(2, n);
        }
        else if (value == 1)
        {
            answer = 0;
        }
        else 
        {
            
        }
    }

    return 0;
}
