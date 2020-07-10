#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    getline(cin,input);
    sort(input.rbegin(),input.rend());
    cout << input;
    return 0;
}