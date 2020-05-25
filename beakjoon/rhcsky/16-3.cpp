#include <iostream>
using namespace std;

int main(){
    int input, fibo[3];
    cin >> input;

    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= input; i++)
    {
        fibo[2] = fibo[0] + fibo[1];
        if(fibo[2] >= 15746) fibo[2] -= 15746;
        fibo[0] = fibo[1];
        fibo[1] = fibo[2];
    }
    cout << fibo[1];
    return 0;
}



int my_main()
{
    int input;
    cin >> input;
    int *fibo = new int[1000001];
    for (int i = 0; i < 3; i++)
    {
        fibo[i] = i;
    }
    
    for (int i = 3; i <= input; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2])%15746;
    }
    
    cout << fibo[input];
    return 0;
}