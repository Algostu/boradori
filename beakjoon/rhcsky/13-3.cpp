#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<pair<int,int>,int>> info; //weight, height, rank
    int n, weight, height;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight >> height;
        info.push_back(make_pair(make_pair(weight,height),1));
    }
    
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < n; j++)
        {
            if(i==j) continue;
            else if(info[i].first.first < info[j].first.first && info[i].first.second < info[j].first.second){
                info[i].second++;
            }
        }
    }
    for (auto &&i : info)
    {
        cout << i.second << " ";
    }
    
    return 0;
}