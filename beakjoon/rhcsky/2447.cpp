#include <iostream>
using namespace std;

int main()
{
    int a = 123456;

    for (int i = 0; i < 6; i++)
    {
        cout << a << endl;
        a = a >> 1;
    }
    
    return 0;
}