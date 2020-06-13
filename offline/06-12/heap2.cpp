#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int zmain()
{
    vector<int> v = {40,10,30,2,4,50};
    
    // Make heap
    make_heap(v.begin(),v.end());

    // Push element
    v.push_back(60);
    push_heap(v.begin(),v.end());

    // Pop element
    pop_heap(v.begin(),v.end());
    v.pop_back();

    return 0;
}

int main(){
    priority_queue<int, vector<int>, greater<int>> heap; //Min Heap
    vector<int> a = {7,9,1,5,3,4,8};

    for (auto &&i : a) heap.push(i);

    for (int i = 0; i < 7; i++)
    {
        cout << heap.top();
        heap.pop();
    }
    
    return 0;
}