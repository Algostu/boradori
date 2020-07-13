#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = num*2-1; i > 0; i-=2)
    {   
        for (int k = 0; k < num*2-1-i; k+=2)
        {
            cout << " ";
        }
        
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 3; i <= num*2-1; i+=2)
    {
        for (int k = 0; k < num*2-1-i; k+=2)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
