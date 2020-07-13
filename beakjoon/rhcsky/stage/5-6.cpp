#include <iostream>
using namespace std;

int main()
{
    int num, times=1;
    cin >> num;

    for (int i = 0; i < num*2; ++i)
    {
        for (int j = (i&1); j < num+(i&1); j++){
            cout << ((j&1) ? " " : "*" );
        }
    cout << endl;
    }    
}