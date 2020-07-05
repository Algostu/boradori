/*
Binary Search Algorithm
https://www.acmicpc.net/problem/1920
Solver = Rhcsky
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M,input;
    vector<int> narray, marray;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {scanf("%d",&input); narray.push_back(input);}
    scanf("%d", &M);
    for(int i=0; i<M; i++) {scanf("%d", &input); marray.push_back(input);}

    sort(narray.begin(), narray.end());

    for (auto &&i : marray)
    {
        int left = 0, right = N-1;
        bool poss = false;
        while(left <= right){
            int mid = (left + right)/2;
            if(narray[mid] > i) right = mid-1;
            else if(narray[mid] < i) left = mid+1;
            else{
                printf("1\n");
                poss = true;
                break;
            }
        }
        if(!poss) printf("0\n");
    }
    
    return 0;
}