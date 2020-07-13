#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct node{
  double val, f_a, f_b, f_total;
  vector<node *> children;
  node * parent;
};

void solve(int test_num = 0){
  int N, A, B, parent, cnt_a, cnt_b, lower;
  double ans=0, degree_a, degree_b;
  node * cur_node_a, *cur_node_b, *root;
  node nodes[5002]; // 500002
  bool a, b;

  root = &nodes[1];
  nodes[1].val=1; nodes[1].f_a=nodes[1].f_b = 0;nodes[1].parent = NULL;
  cin >> N >> A >> B;

  for(int i=2; i<=N; i++){
    nodes[i].val = i; nodes[i].f_a = nodes[i].f_b = nodes[i].f_total=0;
    scanf("%d", &parent);
    nodes[parent].children.push_back(&nodes[i]);
    nodes[i].parent = &nodes[parent];
  }


  for(int i=1; i<=N; i++){
    if(nodes[i].children.empty()){
      a = b = false;
      cnt_b = cnt_a=0; degree_a = degree_b = 1; cur_node_b = cur_node_a = &nodes[i];
      while(a == false || b == false){
        if(cur_node_a->f_a!=0) a=true;
        if(cur_node_b->f_b!=0) b=true;
        if(a == false){
          cur_node_a->f_a += degree_a/N;
          cnt_a++;
          if(cnt_a % A == 0){
            degree_a++; cnt_a = 0;
          }
          cur_node_a = cur_node_a->parent;
        }
        if(b == false){
          cur_node_b->f_b += degree_b/N;
          cnt_b++;
          if(cnt_b % B == 0){
            degree_b++; cnt_b = 0;
          }
          cur_node_b = cur_node_b->parent;
        }
        if(cur_node_a==NULL) a=true;
        if(cur_node_b==NULL) b=true;
      }
      lower = cnt_a;
      while(cur_node_a != NULL){
        if(cnt_a >= lower) cur_node_a->f_a += (degree_a-1)/N;
        else { cur_node_a->f_a += degree_a/N;}
        cur_node_a = cur_node_a->parent;
        cnt_a++;
        cnt_a = cnt_a % A;
      }
      lower = cnt_b;
      while(cur_node_b != NULL){
        if(cnt_b >= lower) cur_node_b->f_b += (degree_b-1)/N;
        else cur_node_b->f_b += degree_b/N;
        cur_node_b = cur_node_b->parent;
        cnt_b++;
        cnt_b = cnt_b % B;
      }
    }
  }

  for(int i=1; i<=N; i++){
    nodes[i].f_total = nodes[i].f_a + nodes[i].f_b - (nodes[i].f_a)*(nodes[i].f_b);
    printf("f_a : %f f_b : %f f_total : %.5f\n", nodes[i].f_a, nodes[i].f_b, nodes[i].f_total);
    ans += nodes[i].f_total;
  }

  /*
  printf("Case #%d: %d\n", test_num, leaf_node.size());
  */

  printf("Case #%d: %.5f\n", test_num, ans);
}

int main(void){
  int T;
  cin >> T;
  for(int i = 0; i<T; i++){
      solve(i+1);
  }
}
