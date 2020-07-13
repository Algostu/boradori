#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string dp[101][101]{};

string string_add(string a, string b){
    int sum{};
    string res;
    while(!a.empty() || !b.empty()||sum){
        if(!a.empty()){
            sum += a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        res.push_back((sum%10)+'0');
        sum /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string combination(int n, int m){
    if(n==m||m==0) return "1";
    if(dp[n][m]!="") return dp[n][m];
    return dp[n][m] = string_add(combination(n-1,m-1),combination(n-1,m));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin >> n >> m;

    cout << combination(n,m);
    return 0;
}