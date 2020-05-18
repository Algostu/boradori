#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 12345;

    while(a>10){
        cout << "The a is = " << a << endl;
        cout << a%10 << "   ";
        cout << (a/=10) << endl;
        cout << (4)%10;
    }    
    return 0;
}