#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
    cin >> N;
    int minVal[2][3], maxVal[2][3];
    int arr[N+1][3];
    for(int i=1; i<=N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    minVal[0][0] = maxVal[0][0] = arr[1][0];
    minVal[0][1] = maxVal[0][1] = arr[1][1];
    minVal[0][2] = maxVal[0][2] = arr[1][2];

    for(int i=2; i<=N; i++){ 
        
        minVal[1][2] = arr[i][2] + min(minVal[0][2], minVal[0][1]);
        minVal[1][0] = arr[i][0] + min(minVal[0][0], minVal[0][1]);
        minVal[1][1] = arr[i][1] + min({minVal[0][0], minVal[0][1], minVal[0][2]});
        
        maxVal[1][2] = arr[i][2] + max(maxVal[0][2], maxVal[0][1]);
        maxVal[1][1] = arr[i][1] + max({maxVal[0][0], maxVal[0][1], maxVal[0][2]});
        maxVal[1][0] = arr[i][0] + max(maxVal[0][1], maxVal[0][0]);

        memcpy(minVal[0], minVal[1], sizeof(int)*3);
        memcpy(maxVal[0], maxVal[1], sizeof(int)*3);
    }

    cout << max({maxVal[0][0], maxVal[0][1], maxVal[0][2]}) << " " << min({minVal[0][0], minVal[0][1], minVal[0][2]}) << endl;
        return 0;
}
