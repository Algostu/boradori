#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, input;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    scanf("%d",&N);
    scanf("%d", &input);
    printf("%d\n", input);
    maxheap.push(input);
    for (int i = 0; i < N-1; i++)
    {
        scanf("%d", &input);
        if(input < maxheap.top()) maxheap.push(input);
        else minheap.push(input);

        if((int)maxheap.size() - (int)minheap.size() > 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if((int)minheap.size() - (int)maxheap.size() > 0){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        printf("%d\n",maxheap.top());
    }
    

    return 0;
}