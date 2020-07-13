#include <iostream>
using namespace std;

long d[40];
long fibo(int);

int main()
{
    int N, input;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if(input == 0){
            cout << 1 << " " << 0 << endl;
        }
        else cout << fibo(input-1) << " " << fibo(input) << endl;
    
    }
    
    return 0;
}

long fibo(int a){
    if(a==0) return 0;
    if(a==1) return 1;
    if(d[a] != 0) return d[a];
    return d[a] = fibo(a-1) + fibo(a-2);
}