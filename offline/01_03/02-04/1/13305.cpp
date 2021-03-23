#include <bits/stdc++.h>

using namespace std;

class city{
	public:
		int loc;
		unsigned long long price;
		
		city(){}
		
		city(int loc, int price){
			this->loc = loc;
			this->price = price; 
		}
};

bool operator< (city const & a, city const & b){
	return a.price < b.price;
}
	
void solve(){
	int cursor;
	int n_city = 0;
	int dist[100000];
	city cities[100000];
	
	cin >> n_city;
	
	// get input
	for (int loc=0; loc<n_city-1; loc++){
		cin >> dist[loc];
	}
	dist[n_city-1] = 0;
	
	// ������������ �Ÿ� ������ �ٽ� Assign 
	int total_distance = 0;
	for (int loc=n_city-1; loc>=0; loc--){
		total_distance += dist[loc];
		dist[loc] = total_distance;
	}
	
	// ���� �ޱ� 
	for (int loc=0; loc<n_city; loc++){
		cities[loc].loc = loc;
		cin >> cities[loc].price;
	}
	
	// ���ݼ����� ����  
	sort(cities, cities + n_city-1);
	
//	for(int i=0; i<n_city; i++){
//		printf("city %d cost: %d loc: %d\n", i, cities[i].price, cities[i].loc);
//	}
	
	// Greedy ������� �ּ� ���� ����  
	unsigned long long int result=0;
	int current_loc = n_city-1;
	
	for(int i=0; i<n_city-1; i++){
		if (cities[i].loc < current_loc){
			result += cities[i].price * (dist[cities[i].loc] - dist[current_loc]);
			current_loc = cities[i].loc;
		}
	}
	
	// ���� ���  
	printf("%llu\n", result);
//	printf("%llu\n", 1000000ull * 1000000);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}
