#include <sstream>
#include <iostream>

using namespace std;

int main() {

    string input;
    int cnt=0;
    getline(cin,input);
    if(*input.begin() == ' ') input.erase(0,1);
    if(*input.end() == ' ') input.erase(input.length()-1,1);

    istringstream f(input);
    while (getline(f,input,' '))
    {
        // cout << input << " | ";
        cnt ++;
    }

    cout << cnt;
}