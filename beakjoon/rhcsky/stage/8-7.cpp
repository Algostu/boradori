#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    string input, A, B;
    int numA, numB;

    getline(cin,input);
    A = input.substr(0,3);
    B = input.substr(4,3);

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    istringstream(A) >> numA;
    istringstream(B) >> numB;

    if(numA>numB)
        cout << numA;
    else
        cout << numB;

    return 0;
}