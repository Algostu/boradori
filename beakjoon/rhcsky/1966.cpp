#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int,int>> que, importance;
    int N, num, index, input;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &num, &index);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &input);
            que.push_back({i,input});
        }
        copy(que.begin(),que.end(),importance.begin());
        sort(importance.rbegin(),importance.rend());

    }
    
    return 0;
}