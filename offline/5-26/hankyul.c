#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

typedef struct __shark{
	int r;
	int c;
	int s;
	int d;
	int z;
	int cut;
} shark;

typedef struct __pool{
	int arr[30];
	int count;
} pool;

void fight(shark * sharks, int * arr, int * count){
	int max=0, max_index=0;
	for(int i = 0; i<*count; i++){
		if(sharks[arr[i]].z > max){
			max = sharks[arr[i]].z;
			max_index = i;
		}
	}
	
	for(int i = 0; i<*count; i++){
		if(i != max_index) sharks[arr[i]].cut =1;	}
	
	arr[0] = arr[max_index];
	*count = 1;
}

void move_shark(shark * shark, pool (*swim_pool)[100], int R, int C, int index){
	int r, c, temp, found = 0;
	r = shark->r; c = shark->c;
	
	// remove from origin pool
	for(int i = 0; i<swim_pool[r][c].count; i++){
		if(swim_pool[r][c].arr[i] == index){
			found = 1;
			swim_pool[r][c].count--;
		}
		
		if(found == 1){
			swim_pool[r][c].arr[i] = swim_pool[r][c].arr[i+1];
		}
	}
	
	// update where
	switch(shark->d){
		case 1:
			if((shark->s / (R-1)) & 1) {shark->r = (R-1) - shark->r; shark->d = 2;}
			break;
		
		case 2:
			if((shark->s / (R-1)) & 1) {shark->r = (R-1) - shark->r; shark->d = 1;}
			break;
		
		case 4:
			if((shark->s / (C-1)) & 1) {shark->c = (C-1) - shark->c; shark->d = 3; 
			//printf("z : %d c : %d \n",shark->z, shark->c);}
			}
			break;
		
		case 3:
			if((shark->s / (C-1)) & 1) {shark->c = (C-1) - shark->c; shark->d = 4; 
			//printf("z : %d c : %d \n",shark->z, shark->c);}
			}
			break;
	}
	
	r = shark->r; c = shark->c;
	
	switch(shark->d){
		case 1:
			temp = shark->s % (R-1);
			if(r-temp > 0) shark->r = r-temp;
			else { shark->r = temp - r; shark->d = 2; }
			break;
		
		case 2:
			temp = shark->s % (R-1);
			if(r+temp < R) shark->r = r+temp;
			else { shark->r = 2 * (R-1) - (r + temp); shark->d = 1; }
			break;
		
		//left
		case 4:
			temp = shark->s % (C-1);
			if(c-temp > 0) shark->c = c-temp;
			else { shark->c = temp - c; shark->d = 3; }
			//printf("z : %d c : %d temp : %d\n",shark->z, shark->c, temp);
			break;
		
		// right
		case 3:
			temp = shark->s % (C-1);
			if(shark->c+temp < C) shark->c = shark->c+temp;
			else { shark->c = 2 * (C-1) - (c + temp); shark->d = 4; }
			//printf("z : %d c : %d temp : %d\n",shark->z, shark->c, temp);
			break;
	}
	
	// add shark to new place
	
	swim_pool[shark->r][shark->c].arr[swim_pool[shark->r][shark->c].count++] = index;
}

void solve(int test_num){
	int R, C, M;
	pool swim_pool[100][100];
	int get = 0;
	shark sharks[100];
	
	// initialize pool
	for(int i = 0; i<100; i++){
		for(int j = 0; j<100; j++){
			swim_pool[i][j].arr[0] = 0;
			swim_pool[i][j].count = 0;
		}
	}
	
	
	scanf("%d %d %d", &R, &C, &M);
	
	for(int i = 0; i<M; i++){
		scanf("%d %d %d %d %d", &sharks[i].r, &sharks[i].c, &sharks[i].s, &sharks[i].d, &sharks[i].z);
		sharks[i].cut = 0;
		swim_pool[--sharks[i].r][--sharks[i].c].arr[swim_pool[sharks[i].r][sharks[i].c].count++] = i;
	}
	
	
	// initial state
	//for(int i = 0; i<R; i++){
	//	for(int j = 0; j<C; j++){
	//		if(swim_pool[i][j].count != 0){
	//			printf("%4d", sharks[swim_pool[i][j].arr[0]].z);	//		} else printf("%4d", 0);
	//			
	//	}
	//	printf("\n");
	//}	
	
	
	int temp;
	int index;
	
	for(int q = 0; q<C; q++){
		// fishing
		for(int i = 0; i<R; i++){
			if(swim_pool[i][q].count != 0){
				get += sharks[swim_pool[i][q].arr[0]].z;
				sharks[swim_pool[i][q].arr[0]].cut = 1;
				swim_pool[i][q].arr[0] = 0;
				swim_pool[i][q].count--; 
				break;
			}	
		}
		
		// move sharks
		for(int i = 0; i<M; i++){
			if(sharks[i].cut != 1) move_shark(sharks+i, swim_pool, R, C, i);
		}
		
		// if there are more than one shark in a pool, fight
		for(int i =0; i<R; i++){
			for(int j= 0; j<C; j++){
				if(swim_pool[i][j].count > 1){
					fight(sharks, swim_pool[i][j].arr, &swim_pool[i][j].count);
				}
			}
		}
		
		// debug
		printf("fihser : %d get : %d===========\n", q, get);
		for(int i = 0; i<R; i++){
			for(int j = 0; j<C; j++){
				if(swim_pool[i][j].count != 0){
					printf("%4d", sharks[swim_pool[i][j].arr[0]].z);				} else printf("%4d", 0);
				
			}
		printf("\n");
		}	
	}
	printf("%d\n", get);
	
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

