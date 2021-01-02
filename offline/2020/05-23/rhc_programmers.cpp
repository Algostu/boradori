#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    vector<string> lines = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
        };

    vector<pair<unsigned long long,int>> times;
    int Y,Mo,D,H,M,idx=0;
    int pre_Y,pre_Mo,Pre_D;
    float S,P;
    for (auto &&i : lines)
    {
        cout << "idx is " << idx << endl;
        if(idx =! 0){
            pre_Y = Y, pre_Mo = Mo, Pre_D = D;
            sscanf(i.c_str(),"%d-%d-%d %d:%d:%f %fs",&Y,&Mo,&D,&H,&M,&S,&P);
            if (pre_Y==Y && pre_Mo==Mo && (Pre_D==D+1 || Pre_D == D) && H==24 && M==59)
            {
                cout << "im in";
                times.push_back(make_pair(H*3600000+M*60000+S*1000,D));
            }
            // printf("%d %d %f %f\n",H,M,S,P);
        }
        else{
            sscanf(i.c_str(),"%d-%d-%d %d:%d:%f %fs",&Y,&Mo,&D,&H,&M,&S,&P);
            cout << "Hello";
            times.push_back(make_pair(H*3600000+M*60000+S*1000,D));
            printf("%d %d %f %f\n",H,M,S,P);
            cout << "???";
        }
        idx++;
    }

    for (auto &&i : times)
    {
        cout << i.first << " || " << i.second << endl;
    }
    cout << times.size();
    return 0;
}
