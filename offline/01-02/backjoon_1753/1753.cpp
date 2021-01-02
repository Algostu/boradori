#include <bits/stdc++.h>

#define INF 987654321

using namespace std;


class Edge {
	public:
	int from;
	int to;
	int weight;
};

class shortestPath{
	public:
	int idx;
	int val;
	int checked;
};

class Graph{
	public:
	int V;
	int E;
};

void solve(){
	int starting_node;
	Graph G;
	vector<vector<Edge>> adjacency_list;
	vector<shortestPath> answer;
	map<int, shortestPath> shortest_cost;
	cin >> G.V >> G.E;
	cin >> starting_node;
	
	for(int i=0; i<G.V+10; i++){
		vector<Edge> temp;
		shortestPath p;
		p.checked = false;
		p.val = INF-i;
		p.idx = i;
		adjacency_list.push_back(temp);
		answer.push_back(p);
		shortest_cost[INF-i] = p;
	}
	
	int origin_val = answer[starting_node].val;
	answer[starting_node].val = 0;
	shortest_cost.erase(origin_val);
	shortest_cost[0] = answer[starting_node];
	
	for(int i=0; i<G.V; i++){
		bool exist;
		exist = false;
		Edge e;
		cin >> e.from >> e.to >> e.weight;
		// neighbor query for existing directed edge
		for (int j=0; j<adjacency_list[e.from].size(); j++){
			if(e.to == adjacency_list[e.from][j].to){
				exist = true;
				if(e.weight < adjacency_list[e.from][j].weight){
					adjacency_list[e.from][j].weight = e.weight;
				}
			}
		}
		// if directed edge not exist
		if(!exist){
			adjacency_list[e.from].push_back(e);
		}
	}
	
	// check input are stored into vector of vector s
//	for (int i=1; i<=G.E; i++){
//		for (int j=0; j<adjacency_list[i].size(); j++){
//			Edge e = adjacency_list[i][j];
//			printf("from: %d to: %d weight: %d\n", e.from, e.to, e.weight);
//		}
//	}
	
	for(int i=0; i<G.V; i++){
		int lowest_cost = shortest_cost.begin()->first;
		int idx = shortest_cost.begin()->second.idx;
		shortest_cost.erase(lowest_cost);
		cout << idx << endl;
		for(int j=0; j<adjacency_list[idx].size(); j++){
			Edge e = adjacency_list[idx][j];
			if(answer[e.to].val > lowest_cost + e.weight){
				shortest_cost.erase(answer[e.to].val);
				answer[e.to].val = lowest_cost + e.weight;
				shortest_cost[answer[e.to].val] = answer[e.to];
			}
		}
	}
	
	for(int i=1; i<=G.V; i++){
		if (answer[i].val >= INF-G.V)
			cout << "INF" << endl;
		else
			cout << answer[i].val << endl;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}

