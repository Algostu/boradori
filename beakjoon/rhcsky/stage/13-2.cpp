#include <iostream>
using namespace std;

int main()
{
    int input,sum,digit;
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        sum = i;
        digit = i;
        while(digit){
            sum += digit%10;
            digit /=10;
        }

        if(input == sum){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}