#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    int N;
    scanf("%d",&N);
    vector<int> v;
    vector<int> mp[N];
    vector<pair<pair<int,int>,int>> rest;

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a);
        v.push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d",&a);
            mp[i].push_back(a);
        }
    }
    int sum=0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            
            if(v[i] !=0 && v[j]!=0) sum += mp[i][j];
            else if(v[i]==0 || v[j]==0){
                rest.push_back({{i,j},mp[i][j]});
            }
            else continue;
                        
        }
    }
    
    for (auto &&i : rest)
    {
        cout << i.first.first << " " << i.first.second << endl;
    }
    
    
    return 0;
}