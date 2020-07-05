#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(string s, vector<int> a){
    cout << s;
    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int input, n, area;
    while(true){
        area = 0;

        scanf("%d", &n);
        if(n==0) break;
        vector<int> square;
        vector<int> heights;
        int visit[1000000001] = {0,};
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &input);
            square.push_back(input);
            if(visit[input] == 0) heights.push_back(input);
            visit[input] = 1;
        }

        sort(heights.rbegin(),heights.rend());
        if(heights.size() == 1){
            cout << heights[0] * n << endl;
            continue;
        }

        for (int k = 0; k < heights.size()-1; k++)
        {
            int cnt=0;
            auto it = find(square.begin(),square.end(),heights[k]);
            while(it!=square.end()){
                for (int i = it-square.begin(); i<n; i++)
                {
                    if(square[i]!=heights[k]){
                        it = find(it,square.end(),heights[k]);
                        if(area < cnt * heights[k]) area = cnt * heights[k];
                        cnt = 0;
                        break;
                    }
                    cnt++;
                    square[i] = heights[k+1];
                }
            }
        }
        cout << area << endl;
    }
    return 0;
}