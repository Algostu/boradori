#include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

using namespace std;


//ENHANCED
int main(){
    int a, b, c, mul, res[10] = {0,};
    cin >> a >> b >> c;
    mul = a*b*c;
    while (mul)
    {   
        res[mul%10]++;
        mul /=10;
    }

    for(int num : res) cout << num << endl;

    return 0;    
}


//MINE
// int main()
// {
//     int a,b,c,cnt=0;
//     int result[10] = {0,};
//     vector<char> multiply;
//     char temp = '0';

//     cin >> a >> b >> c;

//     string sum = to_string(a*b*c);

//     for (int i = 0; i < sum.length(); i++)
//     {
//         multiply.push_back(sum[i]);
//     }

//     sort(multiply.begin(),multiply.end());

//     for (int i = 0; i <= multiply.size(); i++)
//     {
//         if(temp==multiply[i]) cnt++;
//         else{
//             result[temp-'0'] = cnt;
//             cnt=1;
//             temp=multiply[i];
//         }
//     }
//     for(int a : result){
//         cout << a << endl;
//     }

//     return 0;
// }