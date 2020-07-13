#include <iostream>
using namespace std;

int main()
{
    int n, max = 0, input, sum=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {   
        cin >> input;
        sum += input;
        if(input > max) max = input;
    }

    cout << (float)sum*100/(max*n);

    return 0;
}