#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int N, input, sum=0, output, max=0;
    bool SecondTime = false;
    vector<int> v1, v2(8001,0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&input);
        sum += input;
        v1.push_back(input);
        v2[input+4000]++;
    }
    sort(v1.begin(),v1.end());
    for (int i = 0; i < 8001; i++)
    {
        if(v2[i] > max) max = v2[i];
    }
    for (int i = 0; i < 8001; i++)
    {
        if(v2[i] == max){
            output = i;
            if(SecondTime) break;
            SecondTime = true;
        }
    }

    cout << round((float)sum/v1.size()) << endl;
    cout << v1.at(N/2) << endl;
    cout << output - 4000 << endl;
    cout << v1.back() - v1.front() << endl;
    return 0;
}