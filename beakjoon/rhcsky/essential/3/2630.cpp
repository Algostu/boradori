#include <bits/stdc++.h>
using namespace std;

int m[129][129];
int blue{}, white{};

void DividConquer(int x, int y, int xx, int yy){
    int cb{}, cw{};
    for (int i = y; i < yy+1; i++)
    {
        for (int j = x; j < xx+1; j++)
        {
            if(m[i][j] == 1) cb++;
            else cw++;
        }
    }

    if(cb==0) white++;
    else if(cw==0) blue++;
    else{
        DividConquer(x,y,(x+xx)/2,(y+yy)/2);
        DividConquer((x+xx)/2+1,y,xx,(y+yy)/2);
        DividConquer(x,(y+yy)/2+1,(x+xx)/2,yy);
        DividConquer((x+xx)/2+1,(y+yy)/2+1,xx,yy);
    }
    return;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> m[i][j];
        }
    }
    DividConquer(0,0,N-1,N-1);
    cout << white << endl;
    cout << blue << endl;
    return 0;
}