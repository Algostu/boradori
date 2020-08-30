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

#define MAX_INT 1000000

bool decide_intersect_range(int a, int b, int c, int d, int & lValue, int & rValue){
  if ( a > b ) swap(a, b);
  if (c > d ) swap(c, d);

  if (b >= c && a <= d){
    lValue = a > c ? a : c;
    rValue = b < d ? b : d;
    return true;
  }
  return false;
}

void solve(int test_num = 0){
    pair<int, int> A, B;
    pair<int, int> C, D;

    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cin >> D.first >> D.second;

    double a, b, c, d, e, f;
    double ansX, ansY;
    double m;
    if (A.first == B.first) {
      a = 1;
      b = 0;
      e = A.first;
    }
    else {
      a = (double)(A.second - B.second) / (A.first - B.first);
      b = -1;
      e = a * A.first - A.second;
    }

    if (C.first == D.first) {
      c = 1;
      d = 0;
      f = C.first;
    }
    else {
      c = (double)(C.second - D.second) / (C.first - D.first);
      d = -1;
      f = c * C.first - C.second;
    }

    m = a * d - b * c;

    if (m == 0) {
      printf("0\n");
      return;
    }

    ansX = (d*e - b*f) / m;
    ansY = (a*f - c*e) / m;

    int xLeft, xRight, yDown, yUp;

    xLeft = xRight = yDown = yUp = MAX_INT;

    if (!decide_intersect_range(A.first, B.first, C.first, D.first, xLeft, xRight)){
      printf("0\n");
      return;
    }

    if (!decide_intersect_range(A.second, B.second, C.second, D.second, yDown, yUp)){
      printf("0\n");
      return;
    }

    // printf("a : %llf b %llf c : %llf d : %llf \n", a, b, c, d);
    // cout << m << endl;
    // cout << ansX << " " << ansY << "\n";
    if (ansX >= xLeft && ansX <= xRight && ansY >= yDown && ansY <= yUp){
      printf("1\n");
    } else {
      printf("0\n");
    }

}

int main(void){
  solve();
}
