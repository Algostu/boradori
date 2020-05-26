#include <iostream>
using namespace std;

int main(){
    int input;
    long long fibo[3];
    cin >> input;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= input; i++)
    {
        fibo[2] = fibo[0] + fibo[1];
        fibo[0] = fibo[1];
        fibo[1] = fibo[2];
    }

    if(input == 0) cout << fibo[0];
    else cout << fibo[1];

    return 0;
}