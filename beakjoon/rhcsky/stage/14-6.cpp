#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, x,y;
    vector<pair<int,int>> coordinate;
    cin >> N;

    while (N--)
    {
        scanf("%d %d",&x,&y);
        coordinate.push_back(make_pair(x,y));
    }
    sort(coordinate.begin(),coordinate.end());
    
    for (auto &&i : coordinate)
    {
        printf("%d %d\n",i.first,i.second);
    }
    
    return 0;
}