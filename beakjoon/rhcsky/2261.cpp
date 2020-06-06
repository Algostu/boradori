#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits.h>

using namespace std;

int calDist(pair<int,int> a, pair<int,int> b){
    return (b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second);
}

map<pair<int,int>,int> m;
vector<pair<int,int>> point;

int main()
{
    int n, x_, y_;
    int mini, pos=0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x_, &y_);
        point.push_back({x_,y_});
    }
    
    sort(point.begin(),point.end());
    mini = calDist(point[0],point[1]);
    m[{point[0].second,point[0].first}] = 0;
    m[{point[1].second,point[1].first}] = 0;

    for (int i = 2; i < n; i++)
    {
        while(pos<i){
            int dx = point[i].first - point[pos].first;
            if(dx*dx <= mini) break;
            m.erase({point[pos].second,point[pos].first});
            pos++;
        }

        float dis = sqrt(mini);

        auto left = m.lower_bound({point[i].second-dis,-INT_MAX});
        auto right = m.upper_bound({point[i].second+dis,+INT_MAX});

        for (auto j = left; j != right; j++)
        {
            mini = min(mini, calDist({j->first.second,j->first.first},point[i]));   
        }
        m[{point[i].second, point[i].first}] = 0;
    }

    cout << mini << endl;

    return 0;
}