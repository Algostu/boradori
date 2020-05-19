#include <iostream>
using namespace std;

int main(){
    int result[42] = {0,}, input, cnt=0;
    
    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        if(!result[input%=42])
            cnt+=result[input]=1;
    }
    cout << cnt;
    return 0;
}