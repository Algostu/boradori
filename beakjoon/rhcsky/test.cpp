#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> a[5];
    vector<int> b[5];
    a[0].push_back("Hi ");
    a[0].push_back("My name is");

    cout << a[0][0] << a[0][1] << endl;

    for (int i = 11 - 1; i >= 0; i--)
    {
        b[0].push_back(i);
    }
    for (auto &&i : b[0])
    {
        cout << i << "  ";
    }    
}