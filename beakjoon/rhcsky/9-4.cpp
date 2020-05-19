#include <iostream>
using namespace std;

int main()
{
    int input, sum = 0, x, prev_sum;
    cin >> input;

    for (int i = 1;; i++)
    {
        prev_sum = sum;
        sum += i;
        if (input <= sum)
        {   
            if (i & 1)
            {
                x = input - prev_sum; //분모
                cout << i + 1 - x  << "/" <<  x;
                return 0;
            }
            else
            {
                x = input - prev_sum; //분자
                cout << x  << "/" <<  i + 1 - x;
                return 0;
            }
        }
    }
}