#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX_LINE 1500
#define MAX_ROWS 2001

using namespace std;

class node{
  public:
    int line;
    int visited;
    int del_count[MAX_LINE];
    node * down;
    node * side;

    node(int line) : line(line) {
      down = side = NULL;
      visited = false;
      for (size_t i = 0; i < MAX_LINE; i++) {
        del_count[i] = MAX_ROWS;
      }
    }
};

void make_node(node * arr [], node * arr2 [], int line){
  if(arr[line] == NULL){
    arr[line] = new node(line);
    arr2[line] = arr[line];
  } else {
    arr2[line]->down = new node(line);
    arr2[line] = arr2[line]->down;
  }
}

void bfs(int del_count, node * cur_node_ptr){
  if (cur_node_ptr->down == NULL){
    cur_node_ptr->visited = true;
    bfs(del_count, cur_node_ptr->side);
    for (size_t i = 0; i < MAX_LINE; i++) {
      cur_node_ptr->del_count[i] = cur_node_ptr->side->del_count[i];
    }
    cur_node_ptr->del_count[cur_node_ptr->line] = del_count+1;
  } else {
    cur_node_ptr->visited = true;
    bfs(del_count, cur_node_ptr->side);
    bfs(del_count+1, cur_node_ptr->down);

    for (size_t i = 0; i < MAX_LINE; i++) {
      int a = cur_node_ptr->side->del_count[i];
      int b = cur_node_ptr->down->del_count[i];
      cur_node_ptr->del_count[i] = (a > b ? a : b);
    }
  }

}

void solve(int test_num = 0){
  int N, K, M;
  int from, to, ans=0;

  node * start_arr [MAX_LINE];
  node * cur_arr[MAX_LINE];

  scanf("%d %d %d", &N, &K, &M);

  // initialize
  for (size_t i = 0; i < N; i++) {
    start_arr[i] = cur_arr[i] = NULL;
  }

  // input rows
  for (size_t i = 0; i < K; i++) {
    scanf("%d %d", &from, &to);

    from--; to--;

    make_node(start_arr, cur_arr, from);
    make_node(start_arr, cur_arr, to);

    cur_arr[from]->side = cur_arr[to];
    cur_arr[to]->side = cur_arr[from];
  }

  for (size_t i = 0; i < N; i++) {
    bfs(0, start_arr[i]);
  }

  // input start, end
  for (size_t i = 0; i < M; i++) {
    scanf("%d %d", &from, &to);

    from--; to--;

    if(start_arr[from] == NULL){
      if(from!=to){
        ans += -1;
      }
    }
    else {
      int del_count = start_arr[from]->del_count[to];
      if (del_count == MAX_ROWS){
        ans += -1;
      } else {
        ans += del_count;
      }
    }

  }


  printf("Case #%d\n", test_num);
  printf("%d\n", ans);
}

int main(int argc, char** argv){
  freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  for(int i = 0; i<T; i++){
      solve(i+1);
  }
}
