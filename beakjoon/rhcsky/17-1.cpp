#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K, input, cnt=0;
    vector<int> coins;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&input);
        coins.push_back(input);
    }
    
    for (int i = N - 1; i >= 0; i--)
    {
        if(K >= coins[i]){
            cnt += K / coins[i];
            K %= coins[i];
        }
        if(K==0) break;
    }
    
    cout << cnt;
    
    return 0;
}