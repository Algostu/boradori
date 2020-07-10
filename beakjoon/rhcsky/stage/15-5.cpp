#include <iostream>
using namespace std;

int N, res=0;
int col[15];
void N_Queen(int);
bool isValid(int);

int main()
{
    cin >> N;
    N_Queen(0);
    cout << res;
    return 0;
}

void N_Queen(int cnt){
    if(cnt == N){
        res++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        col[cnt] = i;
        if(isValid(cnt)) N_Queen(cnt+1);
    }
}

bool isValid(int cnt){
    for (int i = 0; i < cnt; i++)
    {
        if(col[i] == col[cnt] || abs(col[cnt]-col[i])==cnt-i) return false;
    }
    return true;
}