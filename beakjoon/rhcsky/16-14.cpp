#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    char s1[1001], s2[1001];
    scanf("%s %s", &s1, &s2);
    
    int dp[strlen(s1)+1][strlen(s2)+1], i ,j;
    for (int i = 0; i < strlen(s1)+1; i++)
    {
        memset(dp[i],0,sizeof(int)*(strlen(s2)+1));
    }
    for (i = 1; i<1+strlen(s1); i++) {
        for (j = 1; j<1+strlen(s2); j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[i-1][j-1];
    return 0;
}
// 이 문제는 너무 풀기 어려웠어서 다음 페이지의 자료를 많이 참고하였다.
// http://melonicedlatte.com/algorithm/2018/03/15/181550.html