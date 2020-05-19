#include <iostream>
using namespace std;

int factorial(int);

int main()
{
    int input;
    cin >> input;
    cout << factorial(input);
    return 0;
}

int factorial(int a){
    if(a==0 || a==1) return 1;
    
    return factorial(a-1)*factorial(a-2);
}