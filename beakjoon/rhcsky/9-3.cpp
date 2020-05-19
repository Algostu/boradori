#include <iostream>
using namespace std;

int main()
{
    int input, sum=1;
    cin >> input;

    for (int i = 0; ; i++)
    {   
        sum += 6*i;
        if (input <= sum)
        {
            cout << i+1;
            return 0;
        }
    }
    return 0;
}