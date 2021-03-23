#include <bits/stdc++.h>

using namespace std;

class sampleClass{
   public: 
        
        int i = 0;
        int p = 1;
};

void solve(){ 
    cout << "hello world\n"; 
    cout << "hello world this is master branch\n"; 
    sampleClass inst = sampleClass();
    // some logic go here
    for (int i = 0; i<10; i++){
        inst.i += 1;
        inst.p += 10;
        printf("%d\n", i);
    }
    return;
}

int main(void){

    solve();

    return 0;
}
