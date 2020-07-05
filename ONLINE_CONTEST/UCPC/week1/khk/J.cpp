#include <iostream>
#include <cstring>
using namespace std;


class DV
{
	char names[100][25];
	long long d[100][100];
	int N;
	public:
		DV(int n)
			:N(n)
		{
			printf("%d\n", N);
		
			for(int i =0;i<N;i++){
				for(int j=0;j<N;j++){
					d[i][j] = 1000000;
				}
			}
		}
		
		void set_cost(int i, int j, int cost){
			if(d[i][j] > cost) d[i][j] = cost;
		}
		
		void set_name(int i, const char * name){
			strcpy(names[i], name);	
		}
		
		int get_minimum_cost(char (*path)[25], int len){
			int sum = 0;
			int start, end;
			
			for(int j=0; j<N; j++)
				if(strcmp(names[j], path[0])==0){
					start = j;
					break;
			}
			
			for(int i=0; i<len-1;i++){
				for(int j=0; j<N; j++)
					if(strcmp(names[j], path[i+1])==0){
						end = j;
						break;
					}
				printf("[%d]%s -> %s : %lld\n", i, path[i], path[i+1], d[start][end]);
				sum += d[start][end];
				start = end;					
			}
			
			return sum;
		}
		
		int init_minimum_cost(){
			for (int k = 0; k < N; ++k) {

   				for (int i = 0; i < N; ++i) {

       				for (int j = 0; j < N; ++j) {
						//set_cost(i, j, d[i][k]+d[k][j]);
						
        				if (d[i][j] > (d[i][k] + d[k][j])) {
                			d[i][j] = d[i][k] + d[k][j];
							printf("%d -> %d : %lld\n", i, j, d[i][j]);
            			}
						

        			}
   				}
			}
		}
	
};

int solve(void){
	
	char names[100][25];
	char path[200][25];
	char type_path[50];
	char start[50], end[50];
	char nailro[5][40] = {
		"Mugunghwa", "ITX-Saemaeul", "ITX-Cheongchun",
		"S-Train", "V-Train"
	};
	
	int N, R, M, K, cost, s, e;
	bool find_s, find_e, special_price, package;
	
	cin >> N >> R;
	
	DV none_Rail(N), Rail(N);
	
	for(int i=0; i<N; i++)
	{
		cin >> names[i];
		none_Rail.set_name(i, names[i]);
		Rail.set_name(i, names[i]);
	}
	
	cin >> M;
	
	for(int i=0; i<M; i++)
		cin >> path[i];
	
	cin >> K;
	
	for(int i=0; i<K; i++)
	{
		find_s = find_e = package = special_price = false;
		
		cin >> type_path >> start >> end >> cost;
		
		// find name
		for(int j = 0; j<N; j++)
		{
			if(strcmp(start, names[j]) == 0)
			{
				s = j;
				find_s = true;
			}
			
			if(strcmp(end, names[j]) == 0)
			{
				e = j;
				find_e = true;
			}
			
			if(find_s==true && find_e==true) break;
		}
		
		// 50% sale
		for(int j=0; j<3; j++)
			if(strcmp(type_path, nailro[j])==0)
				special_price = true;
				
		// free		
		for(int j=3; j<5; j++)
			if(strcmp(type_path, nailro[j])==0)
				package = true;
						
		none_Rail.set_cost(s, e, cost);
		none_Rail.set_cost(e, s, cost);
		if(special_price == true)
			Rail.set_cost(s, e, cost/2);
			Rail.set_cost(e, s, cost/2);
		if(package == true)
			Rail.set_cost(s, e, 0);
			Rail.set_cost(e, s, 0);
	}
	
	int min_cost = 99999;
	int cost_r, cost_none_r;
	
	none_Rail.init_minimum_cost();
	Rail.init_minimum_cost();	
	cost_none_r = none_Rail.get_minimum_cost(path, K);
	cost_r = Rail.get_minimum_cost(path, K);
	
	printf("%s\n", cost_none_r >= cost_r ? "No" : "Yes");
		
	
}

int main(void){
	solve();
	return 0;
}

