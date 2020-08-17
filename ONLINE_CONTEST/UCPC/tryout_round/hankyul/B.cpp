/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

string examples[] = {
    "-",
    "1",
    "-2",
    "1-3",
    "-2-4",
    "1-3-5",
    "-2-4-6",
    "1-3-5-7",
    "-2-4-6-8",
    "1-3-5-7-9",
    "1-3-5-7-10",
    "-2-4-6-8-11",
    "1-3-5-7-9-12",
    "1-3-5-7-10-13",
    "-2-4-6-8-11-14",
    "1-3-5-7-9-12-15",
    "1-3-5-7-10-13-16",
    "-2-4-6-8-11-14-17",
    "1-3-5-7-9-12-15-18",
    "1-3-5-7-10-13-16-19",
    "-2-4-6-8-11-14-17-20",
    "1-3-5-7-9-12-15-18-21"
};

string short_ver_examples[] = {
    "1-3-5-7-9-12-15-1...", // 23 % 3 == 2 -- 9
    "1-3-5-7-10-13-16-...", // 21 % 3 == 0 -- 96 100
    "-2-4-6-8-11-14-17...", // 22 % 3 == 1 -- 97
};

int mod_10(int a, int b, int mod){
    long long int result = a % mod;
    if (b==0) return result;

    int m = 10 % mod;

    for(int i=0; i<31; i++){
      if( (b >> i) & 1 ){
        result *= m;
        result %= mod;
      }
      m *= m; m %= mod;
    }

    return result;
}

void solve(){
    int a, b;
    scanf("%d %d", &a, &b);

    if((a <= 15 && b==0) || (a==1 && b==1)){
        printf("%s\n", examples[(int)(a*pow(10, b))].c_str());
    } else {
        int v = floor(log10(a)) + b + 1;
        int rem = mod_10(a, b, v+1);
        int ans = rem - (v-3);
        if (v==2) ans = rem;
        if (ans != 1 && ans != 2) ans = 0;
        printf("v : %d rem : %d ans : %d \n", v, rem, ans);
        printf("%s\n", short_ver_examples[ans].c_str());
    }

}

int main()
{
   int T;
   cin >> T;

   for (int i = 0; i < T; i++) {
       solve();
   }

}
