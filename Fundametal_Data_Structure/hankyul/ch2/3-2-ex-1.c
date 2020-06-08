#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y, Z) \
if(((X) = (Z)malloc((Y)))==NULL){\
  fprintf(stderr, "malloc error"); exit(EXIT_FAILURE);\
}

typedef struct __elem{
	int key;
} elem;

elem * stack;
int capacity = 1;
int top = -1;

void create_stack();
void stackFull();
elem pop();
void push(elem);
bool isEmpty();
bool isFull();

void create_stack(){
	MALLOC(stack, sizeof(elem) * capacity, elem*);
}

void stackFull(){
	stack = (elem*)realloc(stack, 2 * capacity * sizeof(elem));
	capacity *= 2;
}

elem pop(){
	elem null_elem = {-1};
	if(isEmpty()) return null_elem;
	return stack[top--];
}

void push(elem a){
	if(isFull()){
		stackFull();
	}
	stack[++top] = a;
}

bool isEmpty(){
	if(top == -1) return true;
	else return false;
}

bool isFull(){
	if(top+1 == capacity) return true;
	else return false;
}

void solve(int test_num){
	create_stack();
	elem temp;
	int K;
	
	scanf("%d", &K);
	
	int max_num_elem = pow(2, K) + 1;
	for(int i = 0; i<max_num_elem; i++){
		temp.key = i;
		push(temp);
	}
	printf("capacity : %d\n", capacity);
	
}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(i+1);
  // }

  solve(0);

	return 0;
}

