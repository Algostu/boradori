#include <bits/stdc++.h>

using namespace std;

class city{
	public:
		int loc;
		int price;
		
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
	long long int result=0;
	int cursor;
	int n_city = 0;
	int dist[100000];
	city cities[100000];
	
	cin >> n_city;
	
	int total_distance = 0;
	int current_loc = n_city-1;
	dist[n_city-1] = 0;
	
	for (int loc=0; loc<n_city-1; loc++){
		int temp;
		cin >> temp;
		dist[loc] = temp;
	}
	
	for (int loc=n_city-1; loc>=0; loc--){
		total_distance += dist[loc];
		dist[loc] = total_distance;
	}
	
	for (int loc=0; loc<n_city; loc++){
		cities[loc].loc = loc;
		cin >> cities[loc].price;
	}
	
	sort(cities, cities + n_city);
	
	for(int i=0; i<n_city; i++){
		if (cities[i].loc < current_loc){
			result += cities[i].price * (dist[cities[i].loc] - dist[current_loc]);
			current_loc = cities[i].loc;
		}
	}
	
	printf("%lld\n", result);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}

