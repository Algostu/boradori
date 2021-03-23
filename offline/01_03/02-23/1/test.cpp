#include <bits/stdc++.h>

using namespace std;

struct hello{
    int x;
    int y;
    int z;

    bool operator<(const hello & copy) const {
        return this->z < copy.z;
    }
};

int main(void){
    set<hello> heap;

    heap.insert({0, 1, 1});
    heap.insert({0, 2, 2});
    heap.insert({0, 1, 3});
    heap.insert({0, 1, 4});

    auto front = heap.begin();
    heap.erase(front);
    cout << "front.z: " << front->z << endl;
    heap.insert({0, 1, -1});

    for(auto &item:heap){
        cout << item.z << endl;
    }

    return 0;
}
