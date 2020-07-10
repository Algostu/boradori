#include <iostream>
using namespace std;

int main()
{
    int n;
    int sums[1000001] = {0,};

    scanf("%d", &n);

    for(int i = 2; i <n+1; i++) {
        sums[i] = sums[i-1] + 1;
        if (i % 2 == 0) sums[i] = min(sums[i], sums[i/2] + 1);
        if (i % 3 == 0) sums[i] = min(sums[i], sums[i/3] + 1);
    }

    cout << sums[n];
    
    return 0;
}