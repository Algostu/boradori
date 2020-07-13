/*
25-2 와 25-2_STL 비교
25-2는 직접 heap과 heap operator를 구현하여 사용하였고,
25-2_STL은 표준 C++ 라이브러리(Standard Template Library)를 이용하여 제공된 템플릿으로 힙을 사용
결과적으로 구동시간은 20ms로 같았지만 메모리는 STL이 500KB정도 더 컷다.
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N,input;
    priority_queue<int, vector<int>, greater<int>> heap;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        if(input == 0){
            if(heap.size() == 0) printf("0\n");
            else {printf("%d\n",heap.top()); heap.pop();}
        }
        else heap.push(input);
    }
    
    return 0;
}