#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;


class DV
{
	map<string,int> names;
	double d[100][100];
	int N;
	public:
		DV(int n)
			:N(n)
		{
			for(int i =0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j) d[i][j] = 0;
					else d[i][j] = 987654321;
				}
			}
		}

		int get_path_index(const string name){
			return names[name];
		}

		void set_cost(int i, int j, double cost){
			if(d[i][j] > cost) d[i][j] = cost;
		}

		void set_name(int i, const string name){
			names[name] = i;
		}

		double get_minimum_cost(vector<string> path, int len){
			double sums = 0;
			int start, end;

			for(int i=0; i<len-1;i++){
				start = names[path[i]];
				end = names[path[i+1]];

				// printf("[%d]%s -> %s : %f\n", i, path[i].c_str(), path[i+1].c_str(), d[start][end]);
				sums += d[start][end];
			}

			// printf("total : %f\n", sums);
			return sums;
		}

		void init_minimum_cost(){
			for (int k = 0; k < N; ++k) {
   				for (int i = 0; i < N; ++i) {
       				for (int j = 0; j < N; ++j) {
									set_cost(i, j, d[i][k]+d[k][j]);
		        			// 	if (d[i][j] > (d[i][k] + d[k][j])) {
		              //   			d[i][j] = d[i][k] + d[k][j];
									// printf("%d -> %d : %lld\n", i, j, d[i][j]);
		            	// 		}
        			}
   				}
			}
		}

};

void solve(void){
	string names;
	string input;
	vector<string> path;
	string type_path;
	string start, end;
	vector<string> nailro{
		"Mugunghwa", "ITX-Saemaeul", "ITX-Cheongchun",
		"S-Train", "V-Train"
	};

	double cost, R;
	int N, M, K, s, e;
	bool find_s, find_e, special_price, package;

	// cin >> N >> R;
	scanf("%d %lf", &N, &R);

	DV none_Rail(N), Rail(N);

	for(int i=0; i<N; i++)
	{
		cin >> names;
		// scanf("%s", names);
		none_Rail.set_name(i, names);
		Rail.set_name(i, names);
	}

	// cin >> M;
	scanf("%d", &M);

	for(int i=0; i<M; i++){
		cin >> input;
		path.push_back(input);
	}
	// cin >> K;
	scanf("%d", &K);

	for(int i=0; i<K; i++)
	{
		package = special_price = false;

		cin >> type_path >> start >> end;
		scanf("%lf", &cost);

		// find name
		s = Rail.get_path_index(start);
		e = Rail.get_path_index(end);

		// 50% sale
		for(int j=3; j<5; j++)
			if(type_path == nailro[j])
				special_price = true;

		// free
		for(int j=0; j<3; j++)
			if(type_path == nailro[j])
				package = true;

		none_Rail.set_cost(s, e, cost);
		none_Rail.set_cost(e, s, cost);

		if(special_price)
		{
			Rail.set_cost(s, e, cost/2);
			Rail.set_cost(e, s, cost/2);
		}
		else if(package)
		{
			Rail.set_cost(s, e, 0);
			Rail.set_cost(e, s, 0);
		}
		// 이부분은 다른사람 코드를 참고해서 빠진것을 파악했다.
		else{
			Rail.set_cost(s, e, cost);
			Rail.set_cost(e, s, cost);
		}
	}

	double cost_r, cost_none_r;

	none_Rail.init_minimum_cost();
	Rail.init_minimum_cost();
	cost_none_r = none_Rail.get_minimum_cost(path, M);
	cost_r = Rail.get_minimum_cost(path, M);

	// printf("none railro : %f \nrailro : %f \n", cost_none_r, cost_r);
	if(cost_none_r <= cost_r+R ? true : false){
		printf("No\n");
	} else {
		printf("Yes\n");
	}

}

int main(void){
	solve();
	return 0;
}
