#include <iostream>
using namespace std;

int main()
{
    int test, H, W, N;
    cin >> test;
    while (test--)
    {
        cin >> H >> W >> N;
        if(N%H==0) cout << H;
        else cout << N%H;
        // cout << endl;
        // cout << (N-1/H+1) << endl;
        if ((N-1)/H+1 < 10) cout << '0' << (N-1)/H + 1 << endl;
        else cout << (N-1)/H + 1 << endl;
    }
    
    return 0;
}