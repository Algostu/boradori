#include <bits/stdc++.h>


#include <stdio.h>

#define INT_MAX 2147483647 // 최대 정수
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7  // 정점의 수
#define INF 1000    // 무한대 (연결이 없는 경우)
 
int weight[MAX_VERTICES][MAX_VERTICES] = {
  {0,7,INF,INF,3,10,INF},
  {7,0,4,10,2,6,INF},
  {INF,4,0,2,INF,INF,INF},
  {INF,10,2,0,11,9,4},
  {3,2,INF,11,0,INF,5},
  {10,6,INF,9,INF,0,INF},
  {INF,INF,INF,4,5,INF,0}
};

int distance[MAX_VERTICES]; // 시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES];  // 방문한 정점 표시

int choose(int distance[], int n, int found[])
{
  // 현재 distance 배열에서 가장 작은 가중치 값이 위치하고 있는
  // 배열의 인덱스를 찾아 반환하는 함수

  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;

  // 최소값 min을 찾는 반복문이다.
  // 방문한 적이 없는 정점에 대해 distance배열의 값들을 비교한다.
  for (i = 0; i < n; i++)
  {
    // 방문된 적이 없는 정점이고 현재까지의 최소값 min 보다 작다면
    if (distance[i] < min && found[i] == FALSE)
    {
      // 최소값을 의미하는 min 정보를 갱신해준다.
      min = distance[i];

      // 최소값이 등장한 해당 정점의 인덱스를 minpos에 저장한다.
      minpos = i;
    }
  }
  // distnace 배열에서 최소값이 위치하고 있는 인덱스를 반환한다.
  return minpos;
}

void shortest_path(int start_r, int start_c, int dest_r, int dest_c, MAP map_my_team, MAP map_dif, MAP list_dif)
// start 정점부터 n 정점까지의 최단 경로를 찾는 알고리즘
{
  int i, u, w;

  /* 초기화 작업 */
  for (i = 0; i < n; i++)
  {
    // 시작 정점 start를 기준으로 했을 때의 가중치로
    // distance 배열을 초기화 한다.
    distance[i] = weight[start][i];

    // 아직 시작을 안했으므로 방문 표시의 역할을 하는
    // found 배열을 FALSE로 초기화 한다.
    found[i] = FALSE;
  }
  // 시작 정점을 선택했으니 방문여부를 TRUE로 설정한다.
  found[start] = TRUE;
  distance[start] = TRUE;

  for (i = 0; i < n - 1; i++) // 위에서 시작 정점 값을 설정했으므로 여기서는 하나를 뺀 만큼만 반복한다.
  {
    // 최소값이 있는 인덱스의 정보를 u에 저장한다.
    u = choose(distance, n, found);

    // 현재 distance 배열에서 가장 작은 값이 위치한 인덱스는 u이므로
    // u번 정점을 선택을 한다. 선택함과 동시에 TRUE로 값을 써주며 방문 표시를 한다.
    found[u] = TRUE;

    // 최소 가중치가 있는 정점을 집합 S에 추가한 뒤 우리는 갱신할 수 있는 정보가 있다면
    // 그 정보를 갱신해준다. 무한대 (이 PG에서는 1000)에서 정수 거리로 갱신되는 정보나
    // 긴 거리에서 짧은 거리로 갱신되는 정보나 아래의 로직이 그대로 작동한다.
    for (w = 0; w < n; w++)
    {
      // 아직 선택되어 지지 않은 정점이고
      if (found[w] == FALSE)
      {
        // 현재 그 정점까지의 거리 (distance[u]) + 정점 w까지의 거리가
        // 기존의 w정점까지의 거리보다 가깝다면 그 정보를 갱신해준다.
        if (distance[u] + weight[u][w] < distance[w])
        {
          distance[w] = distance[u] + weight[u][w];
        }
      }
    }
  }
}

void main()
{
  shortest_path(0, MAX_VERTICES);
}


#define MAX_PATH_LEN 1000000
using namespace std;
int H, W;
int dir[4][2] = {
		{0,1},{0,-1},{1,0},{-1,0}
};
typedef char (*MAP)[502];
typedef int (*MAP_INT)[502];
struct unit{
	int m, t, a, b;
};
struct node{

}
int DP(int cur_r, int cur_c, int r, int c, MAP_INT memo, MAP map_my_team, MAP map_dif, int * list_dif){
	int ans = MAX_PATH_LEN;
	int temp = 0;
	int new_r=0, new_c=0;
	map_my_team[cur_r][cur_c] = 0;
	if(memo[cur_r][cur_c] != -1) {
		ans = memo[cur_r][cur_c];
		printf("[memo] r : %d c : %d v : %d\n", cur_r, cur_c, ans);
	}
	else {
		printf("[before]r : %d c : %d \n", cur_r, cur_c);
		for(int j=0; j<4; j++){
			if(cur_r+dir[j][0] >0 && cur_r+dir[j][0] <= H && cur_c+dir[j][1] > 0 && cur_c+dir[j][1] <= W){
				if(cur_r+dir[j][0]==r && cur_c+dir[j][1]==c){
					printf("IN\n");
				 	ans = list_dif[map_dif[r][c]];
				 	new_r = r; new_c = c;
					break;
				} else if(map_my_team[cur_r+dir[j][0]][cur_c+dir[j][1]]==1){
					new_r = cur_r+dir[j][0]; new_c = cur_c+dir[j][1];
					temp = list_dif[map_dif[new_r][new_c]]+DP(new_r, new_c, r, c, memo, map_my_team, map_dif, list_dif);
					printf("[middle]r : %d c : %d v : %d \n", cur_r, cur_c, temp);
					if(ans > temp){
						ans = temp;
					}
				}
			}
		}
	}
	printf("[after]r : %d c : %d v : %d \n", cur_r, cur_c, ans);

	memo[cur_r][cur_c] = ans;
	map_my_team[cur_r][cur_c] = 1;
	return ans;
}
void solve(){
	int N, M, K;
	int r, c, n, m, u_idx;
	char map_dif[502][502], map_team_A[502][502], map_team_B[502][502];
	char map_loc[502][502];
	int memo[502][502];
	int list_dif[10];

	cin >> N >> H >> W;

	// get dif index for map_dif
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			scanf("%d", &n);
			map_dif[i][j] = n;
			map_loc[i][j] = -1;
		}
	}

	// get dif value in list_dif
	for(int i=1; i<=N; i++){
		scanf("%d", &n);
		list_dif[i] = n;
	}

	cin >> M;

	vector<unit> units;

	// get unit info
	for(int i=0; i<M; i++){
		scanf("%d %d %d %d", &m, &n, &r, &c);
		unit temp = {m, n, r+1, c+1};
		units.push_back(temp);
		map_loc[r+1][c+1] = n;
	}

	// set possible way
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			if(list_dif[map_dif[i][j]]==-1){
				map_team_A[i][j] = 0;
				map_team_B[i][j] = 0;
				map_loc[i][j] = 3;
			}
			else{
				map_team_A[i][j] = 1;
				map_team_B[i][j] = 1;
			}
		}
	}

	// initailize map
	for(int i=0; i<M; i++){
		int my_team, your_team, flag_comb=0;
		unit u = units[i];
		MAP map_my_team, map_your_team;
		if(u.t==0){
			// team A
			map_my_team = map_team_A; map_your_team = map_team_B;
			my_team = 0; your_team = 1;
		}
		else{
			map_my_team = map_team_B; map_your_team = map_team_A;
			my_team = 1; your_team = 0;
		}

		//printf("r : %d c : %d my_team : %d \n", u.a, u.b, my_team);

		for(int j=0; j<4; j++){
			if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
				if(map_loc[u.a+dir[j][0]][u.b+dir[j][1]] == your_team){
					flag_comb = 1;
					break;
				}
			}

		}
		map_your_team[u.a][u.b] = 0;
		if(flag_comb == 0){
			for(int j=0; j<4; j++){
				if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
					map_your_team[u.a+dir[j][0]][u.b+dir[j][1]] = 0;
				}
			}
		}


	}


	printf("TEAM %d ==================================\n", 0);
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			printf("%d ", map_team_A[i][j]);
		}
		printf("\n");
	}

	printf("TEAM %d ==================================\n", 1);
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			printf("%d ", map_team_B[i][j]);
		}
		printf("\n");
	}


	cin >> K;

	for(int i=0; i<K; i++){
		//printf("Iteration : %d ============================== \n", i);

		scanf("%d %d %d", &u_idx, &r, &c);
		int idx = u_idx-1;
		r = r+1; c = c+1;
		/*
		idx = target_unit index
		r, c = target loc
		H, W = size of map
		units = list of unit
		list_dif = difficulty of each map
		map_dif = index of difficulty of each map
		map_team_A = possible way of A (0)
		map_team_B = possible way of B (1)
		map_loc = {-1 : no one, 0 : A, 1 : B}
		0 = cant go way
		1 = can go way
		*/
		int my_team, your_team, flag_comb=0;
		unit u = units[idx];
		MAP map_my_team, map_your_team;
		if(u.t==0){
			// team A
			map_my_team = map_team_A; map_your_team = map_team_B;
			my_team = 0; your_team = 1;
		}
		else{
			map_my_team = map_team_B; map_your_team = map_team_A;
			my_team = 1; your_team = 0;
		}


		// alread taken by somebody
		if(map_loc[r][c] != -1) continue;

		// it is not possible to go
		if(list_dif[map_dif[r][c]] == -1) continue;

		// check in combat
		for(int j=0; j<4; j++){
			if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
				if(map_loc[u.a+dir[j][0]][u.b+dir[j][1]] == your_team){
					flag_comb = 1;
					break;
				}
			}
		}
		map_my_team[u.a][u.b]=0;
		int distance = shortest_path(u.a, u.b, r, c, map_my_team, map_dif, list_dif);
		map_my_team[u.a][u.b]=1;
		printf("Team %d : from (%d, %d) to (%d, %d)\n", u.t, u.a, u.b, r, c);
		printf("distance : %d\n", distance);

		if(distance >= MAX_PATH_LEN || (flag_comb == 1 && distance > u.m)){
			continue;
		} else {
			// update my team
			for(int j=0; j<4; j++){
				if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
					if(map_loc[u.a+dir[j][0]][u.b+dir[j][1]] == your_team){
						flag_comb = 1;
						int your_r = u.a + dir[j][0], your_c = u.b + dir[j][1];
						int your_flag_comb = 0;
						for(int k=0; k<4; k++){
							if(your_r+dir[k][0] >0 && your_r+dir[k][0] <= H && your_c+dir[k][1] > 0 && your_c+dir[k][1] <= W){
								if(map_loc[your_r+dir[k][0]][your_c+dir[k][1]] == my_team && (your_r+dir[k][0] != u.a && your_c+dir[k][1] != u.b)){
									your_flag_comb = 1;
									break;

								}
							}
						}
						if(your_flag_comb == 0){							for(int k=0; k<4; k++){
								if(your_r+dir[k][0] >0 && your_r+dir[k][0] <= H && your_c+dir[k][1] > 0 && your_c+dir[k][1] <= W){
										map_my_team[your_r+dir[k][0]][your_c+dir[k][1]] = 0;
								}
							}
						}
					}
				}
			}

			// update your team
			map_your_team[u.a][u.b] = 1;
			if(flag_comb == 0){
				for(int j=0; j<4; j++){
					if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
						if(map_loc[u.a+dir[j][0]][u.b+dir[j][1]] == -1)
							map_your_team[u.a+dir[j][0]][u.b+dir[j][1]] = 1;
					}
				}
			} else{
				map_my_team[u.a][u.b] = 0;
			}


			flag_comb = 0;
			// update map_loc
			map_loc[u.a][u.b] = -1;
			map_loc[r][c] = u.t;

			// update unit
			u.a = r; u.b = c;

			// update my team
			map_my_team[u.a][u.b] = 1;
			for(int j=0; j<4; j++){
				if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
					if(map_loc[u.a+dir[j][0]][u.b+dir[j][1]] == your_team){
						flag_comb = 1;
						int your_r = u.a + dir[j][0], your_c = u.b + dir[j][1];
						int your_flag_comb = 0;
						for(int k=0; k<4; k++){
							if(your_r+dir[k][0] >0 && your_r+dir[k][0] <= H && your_c+dir[k][1] > 0 && your_c+dir[k][1] <= W){
								if(map_loc[your_r+dir[k][0]][your_c+dir[k][1]] == my_team && (your_r+dir[k][0] != u.a && your_c+dir[k][1] != u.b)){
									your_flag_comb = 1;
									break;

								}
							}
						}
						if(your_flag_comb == 0){
							for(int k=0; k<4; k++){
								if(your_r+dir[k][0] >0 && your_r+dir[k][0] <= H && your_c+dir[k][1] > 0 && your_c+dir[k][1] <= W){
									if(map_loc[your_r+dir[k][0]][your_c+dir[k][1]] == -1)
										map_my_team[your_r+dir[k][0]][your_c+dir[k][1]] = 1;
								}
							}
						}
					}
				}
			}

			// update your team
			map_your_team[u.a][u.b] = 0;
			if(flag_comb == 0){
				for(int j=0; j<4; j++){
					if(u.a+dir[j][0] >0 && u.a+dir[j][0] <= H && u.b+dir[j][1] > 0 && u.b+dir[j][1] <= W){
						map_your_team[u.a+dir[j][0]][u.b+dir[j][1]] = 0;
					}
				}
			}


		}

		units[idx] = u;

		printf("TEAM %d ==================================\n", 0);
		for(int j=1; j<=H; j++){
			for(int k=1; k<=W; k++){
				printf("%d ", map_team_A[j][k]);
			}
			printf("\n");
		}

		printf("TEAM %d ==================================\n", 1);
		for(int j=1; j<=H; j++){
			for(int k=1; k<=W; k++){
				printf("%d ", map_team_B[j][k]);
			}
			printf("\n");
		}

	}

	for(int i=0; i<units.size(); i++){
		printf("%d %d\n", units[i].a-1, units[i].b-1);
	}
}
int main(void){
	solve();
	return 0;
}
