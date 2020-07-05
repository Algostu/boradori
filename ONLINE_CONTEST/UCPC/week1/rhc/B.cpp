#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,a,b;
    
    vector<pair<int,int>> v,vv,r;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back({a,b});
    }
    vv=v;
    sort(vv.begin(),vv.end());
    
    while(1){
        cout << r.size();
        if(r.size()==1) break;
        for (int i = 0; i < vv.size()-1; i=i+2)
        {
            r.push_back({max(vv[i].first,vv[i+1].first),min(vv[i].second,vv[i+1].second)});
        }
        vv.clear();
        vv=r;
    }
    cout << "F";
    for (auto &&i : r)
    {
        cout << i.first << endl;
        cout << i.second << endl;
    }
    


    return 0;
}