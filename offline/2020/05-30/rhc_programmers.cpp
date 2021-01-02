/*
Programmers Level-3 단어변환
https://programmers.co.kr/learn/courses/30/lessons/43163
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_next(string,string);
void DFS(int, vector<int>[],bool*,int);
int mini = 1000, target_index;

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target) == words.end()) return 0;
    words.insert(words.begin(),begin);
    vector<int> graph[words.size()];
    vector<string>::iterator iter;
    auto itr = find(words.begin(),words.end(),target);
    target_index = distance(words.begin(),itr);
    // Graph 만들기
    for (int i = 0; i < words.size()-1; i++)
    {
        for (int j = i+1; j < words.size(); j++)
        {
            if(i==j) continue;
            if(is_next(words[i],words[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }   
    // DFS구현
    bool check[words.size()] = {false,};
    DFS(0,graph,check,0);

    cout << mini;
    
    return mini;
}

bool is_next(string a, string b){
    int cnt = 0;
    for (auto &&i : a)
    {
        if(b.find(i) != string::npos) cnt++;
        if(cnt == a.size()-1) return true;
    }
    return false;
}

void DFS(int idx, vector<int> graph[], bool check[], int cost){
    check[idx] = true;
    if(idx==target_index){
        if(cost<mini) mini = cost;
        return;
    }
    for (int i = 0; i < graph[idx].size(); i++)
    {
        if(check[graph[idx][i]] == false){
            check[graph[idx][i]] = true;
            DFS(graph[idx][i],graph,check,cost+1);
            check[graph[idx][i]] = false;
        }
    }
}


int main(){
    string begin = "hit", target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log"};
    solution(begin,target,words);
    return 0;
}