#include <iostream>
using namespace std;

#define MAX_ELEMENT 100000

typedef struct
{
    int heap[MAX_ELEMENT];
    int heap_size=0;
}Heap;

void push(Heap *h, int data){
    int i = ++(h->heap_size);
    h->heap[i] = data;

    while(i>1 && h->heap[i] > h->heap[i/2]){
        swap(h->heap[i],h->heap[i/2]);
        i /= 2;
    }
}

int pop(Heap *h){
    int result = h->heap[1];
    swap(h->heap[(h->heap_size)--],h->heap[1]);

    int parent = 1;
    int child = parent*2;
    while(child <= h->heap_size){
        if(child < h->heap_size && h->heap[child] < h->heap[child+1]) child++;
        if(h->heap[child] < h->heap[parent]) break;

        swap(h->heap[child],h->heap[parent]);
        parent = child;
        child *= 2;
    }
    return result;
}

int main()
{
    int N, input;
    scanf("%d", &N);
    Heap h;
    for (int i = 0; i < N; i++)
    {a
        scanf("%d", &input);
        if(input == 0){
            cout << "Heap size is = " << h.heap_size << endl;
            if(h.heap_size==0) printf("0\n");
            else printf("%d\n",pop(&h));
        }
        else push(&h,input);
    }
    
    return 0;
}