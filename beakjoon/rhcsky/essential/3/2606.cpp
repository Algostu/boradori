#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;

void floydWashall(){
    int N,E,a,b,cnt{};
    cin >> N >> E;

    int m[N+1][N+1];
    fill(m[0],m[N+1],INF);

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        m[a][b] = m[b][a] = 1;
    }
    
	for(int k = 1; k < N+1; k++) {
		for(int i = 1; i < N+1; i++) {
			for(int j = 1; j < N+1; j++) {
				if(m[i][k] + m[k][j] < m[i][j]) {
					m[i][j] = m[i][k] + m[k][j];
				}
			}
		} 
	} 

    for (int i = 2; i < N+1; i++)
    {
        if(m[1][i]!=INF) cnt++;
    }
    
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    floydWashall();
    return 0;
}