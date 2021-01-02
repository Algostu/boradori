/*
Programmers Level-3 네트워크
https://programmers.co.kr/learn/courses/30/lessons/43162
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void BFS(int start, vector<int> network[], bool check[]){
    queue<int> q;
    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for (int i = 0; i < network[temp].size(); i++)
        {
            if(check[network[temp][i]]==false){
                q.push(network[temp][i]);
                check[network[temp][i]] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> network[n];
    bool check[n] = {false,};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(computers[i][j] == 1) network[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(check[i] == false) {BFS(i,network,check); answer++;}
    }
    cout << answer;
    return answer;
}

int main(){
    int n = 4;
    vector<vector<int>> computers = {{1,1,0,1},{1,1,1,0},{0,1,1,0},{1,0,0,1}};
    solution(n,computers);
}