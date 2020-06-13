#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
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