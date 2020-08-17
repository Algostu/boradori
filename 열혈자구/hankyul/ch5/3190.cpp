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

using namespace std;

enum DIRS { east, west, north, south };

void calculate_col(int & cur_row, int & cur_col, int i, int dir){
  switch(dir){
    case east:
      cur_col += i;
      break;
    case west:
      cur_col -= i;
      break;
    case north:
      cur_row -= i;
      break;
    case south:
      cur_row += i;
      break;
  }
}

int change_dirs(int cur, int rotate){
  if(rotate == 'C'){
    return cur;
  }
  switch(cur){
    case east:
      if(rotate == 'L') return north;
      else return south;
    case west:
      if(rotate == 'L') return south;
      else return north;
    case south:
      if(rotate == 'L') return east;
      else return west;
    case north:
      if(rotate == 'L') return west;
      else return east;
  }
}

int check_out_of_bound(int cur_row, int cur_col, int & time_elapsed, int dir, int time, int N){
  switch(dir){
    case east:
      cur_col += time;
      if(cur_col > N){
        printf("%d\n", time_elapsed + time - (cur_col - N));
        return true;
      }
      break;
    case west:
      cur_col -= time;
      if(cur_col < 1){
        printf("%d\n", time_elapsed + time - (1 - cur_col));
        return true;
      }
      break;
    case north:
      cur_row -= time;
      if(cur_row < 1){
        printf("%d\n", time_elapsed + time - (1 - cur_row));
        return true;
      }
      break;
    case south:
      cur_row += time;
      if(cur_row > N){
        printf("%d\n", time_elapsed + time - (cur_row - N));
        return true;
      }
      break;
  }

  time_elapsed += time;

  return false;
}



void solve(int test_num = 0){
  int N, K, L;
  int row, col;
  int app_map[102][102];
  vector<pair<int, char>> ch_dirs;
  list<pair<int, int>> snake_body;

  cin >> N >> K;

  for (size_t i = 0; i < 102; i++) {
    for (size_t j = 0; j < 102; j++) {
      app_map[i][j] = 0;
    }
  }

  for (size_t i = 0; i < K; i++) {
    scanf("%d %d", &row, &col);
    app_map[row][col] = 1;
  }

  cin >> L;

  ch_dirs.push_back(make_pair(0, 'D'));
  int time;
  int dir;

  for (size_t i = 0; i < L; i++) {
    scanf("%d", &time); getchar();
    dir = getchar(); getchar();

    ch_dirs.push_back(make_pair(time, dir));
  }

  ch_dirs.push_back(make_pair(time+100, 'C'));

  dir = north;
  int cur_row=1, cur_col=1;
  int time_elapsed = 1; // Test

  snake_body.push_back(make_pair(cur_row, cur_col));
  list<pair<int, int>>::iterator iter;

  for (size_t t = 0; t < L+1; t++) {
    // Debug
    // cout << "row : " << cur_row << " col : " << cur_col << endl;
    pair<int, char> now = ch_dirs[t];
    pair<int, char> next = ch_dirs[t+1];
    dir = change_dirs(dir, now.second);
    time = next.first - now.first;

    int how_many_apple = 0;
    int num_apple = 0;
    int snake_len = snake_body.size();
    iter = snake_body.begin();
    vector<int> num_of_apps;

    num_of_apps.push_back(0);

    int short_time = time+1;
    int new_row, new_col;
    // cout << "TIME : " << time << endl;
    for (size_t i = 1; i <= time; i++) {
      new_row = cur_row; new_col = cur_col;
      calculate_col(new_row, new_col, i, dir);
      if(app_map[new_row][new_col] == 1){
        num_of_apps.push_back(num_apple);
        app_map[new_row][new_col] = 0;
        how_many_apple++;
      }
      else{
        num_of_apps.push_back(num_apple);
        num_apple++;
      }
    }

    // Debug
    // cout << "body size diminish" << endl;
    // for (size_t i = 0; i < num_of_apps.size(); i++) {
    //   cout << num_of_apps[i] << endl;
    // }

    for (size_t i = 0; i < snake_len-1; i++) {
      pair<int, int> body_part = *iter;
      iter++;
      switch(dir){
        case east:{
          int duration = body_part.second - cur_col;
          if(duration > 0 && duration <= time){
              if(body_part.first == cur_row &&  i >= num_of_apps[duration]){
                if(short_time > duration){
                  short_time = duration;
                }
              }
          }
          break;
        }
        case west:{
          int duration = cur_col - body_part.second;
          if(duration > 0 && duration <= time){
              if(body_part.first == cur_row &&  i >= num_of_apps[duration]){
                if(short_time > duration){
                  short_time = duration;
                }
              }
          }
          break;
        }
        case north:{
          int duration = cur_row - body_part.first;

          if(duration > 0 && duration <= time){
              if(body_part.second == cur_col &&  i >= num_of_apps[duration]){
                if(short_time > duration){
                  short_time = duration;
                }
              }
          }
          break;
        }
        case south:{
          int duration = body_part.first - cur_row;
          if(duration > 0 && duration <= time){
              if(body_part.second == cur_col &&  i >= num_of_apps[duration]){
                if(short_time > duration){
                  short_time = duration;
                }
              }
          }
          break;
        }
      }
    }

    if(short_time != time+1){
      // Debug
      // cout << "Body crashed into body\n";
      printf("%d\n", time_elapsed+short_time-1);
      return;
    }

    if(check_out_of_bound(cur_row, cur_col, time_elapsed, dir, time, N)){
      // Debug
      // cout << "Body crashed into wall\n";
      return;
    }

    for (size_t i = 1; i <= time; i++) {
      new_row = cur_row; new_col = cur_col;
      calculate_col(new_row, new_col, i, dir);

      snake_body.push_back(make_pair(new_row, new_col));
    }

    for (size_t i = 0; i < time-how_many_apple; i++) {
      snake_body.pop_front();
    }

    calculate_col(cur_row, cur_col, time, dir);
    // Debug
    // cout << "how many apple : " << how_many_apple << endl;
    // cout << "Body Size : " << snake_body.size() << endl;
  }

}

int main(void){
  solve();
}
