// 미완성
#include <bits/stdc++.h>
using namespace std;

struct Comp{
    vector<pair<int,int>> v[4]; //value, color
    Comp(){
        for (int i = 0; i < 4; i++)
        {
            v[i].resize(4);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    char s;
    cin >> N;
    vector<Comp> c;
    c.resize(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> c[i].v[j][k].first;
            }
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> s;
                if(s=='R') c[i].v[j][k].second = 7;
                if(s=='B') c[i].v[j][k].second = 5;
                if(s=='G') c[i].v[j][k].second = 3;
                if(s=='Y') c[i].v[j][k].second = 2;
            }
        }
    }


    return 0;
}