#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    vector<int> length;
    while(1){
        length.clear();
        for (int i = 0; i < 3; i++)
        {
            cin >> a;
            length.push_back(a);
        }
        if(a==0) break;
        sort(length.begin(), length.end());

        a = length[0];
        b = length[1];
        c = length[2];

        if(a*a+b*b == c*c) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}