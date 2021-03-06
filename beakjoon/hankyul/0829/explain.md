# 17386

## 문제 설명  
해당 문제는 선분끼리의 접점이 생기는지 확인하는 문제이다. 이 문제는 다음 2가지 부분으로 나누어서 풀었다. 첫번째, 두 선분을 직선으로 생각하고 연립방정식의 해를 구한다. 두번째, 첫번째에서 구한 해가 작은 직사각형 범위 안에 포함 되어 있는지 파악한다.

## 연립 연립방정식의 해 구하기  
선분 `L1` 이 두 점`(x1, y1), (x2, y2)`를 지나는 직선이라고 할 때 직선의 방정식은 다음과 같다. `m(x-x1) = (y-y1), m =(y1-y2)/(x1 - x2)` 이 방정식에서 예외가 한가지 있다면 `x = a` 와 같이 좌표평면과 수직인 경우이다. 이 경우는 따로 예외 처리를 해주어야 한다. 아래 코드는 `ax+by=e` 의 형태로 방정식의 계수를 구하는 부분이다.

```C
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
```

연립 방정식을 구하고 나면 연립방정식의 해를 구해야한다. 이 연립 방정식의 해는 성식이가 저번에 알려준 역행렬을 사용하면 된다. 역행렬을 구할 때 역행렬이 존재 하지 않을 경우는 평행한 경우이므로 제외 하면 된다.  

```c
m = a * d - b * c;

if (m == 0) {
  printf("0\n");
  return;
}

ansX = (d*e - b*f) / m;
ansY = (a*f - c*e) / m;
```

## 작은 직사각형 범위 구하기  
이 문제를 푼 당일날 종만북에서 두 범위의 교집합이 생기지 않는 경우에 대해서 공부했다. 공부한 내용을 바탕으로 다음과 같이 교지합이 있는지 없는지 판단하고 만약 있다면 그 범위를 reference 형 변수를 통해서 알려주는 함수를 만들었다.

```c
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
```  
마지막으로 해가 구한 범위 안에 체크만 해주면 끝이다.  
```c
if (ansX >= xLeft && ansX <= xRight && ansY >= yDown && ansY <= yUp){
  printf("1\n");
} else {
  printf("0\n");
}
```

# 2293

## 문제 설명  
이 문제는 절반은 내가 풀었고 절반은 남이 푼 코드를 참고했다. 원래 Top-down 방식으로 풀었으나 메모리 초과 에러를 해결하지 못하고 있었다. 그러던 중 질문하기에 있는 글에있는 정답 글을 보고 해결책을 떠올렸다.(거의 배꼈다) 이 문제의 풀이 원리는 매우 간단하다. `coin[q]_W_k = Sigma(coin[q-1]_W_i) (i = K - coin[q] * j, j>=0)` 하지만 이 공식을 보고 한번에 bottom-up 방식을 생각하기란 매우 힘든 일이다. 따라서 top-down 방식으로 한번 생각한 뒤에 다시 bottom-up 방식을 떠올리는 수 밖에 없다.(물론 바로 bottom-up도 가능한 사람이 있을 것이다.) 위 공식을 적용해서 풀다 보면 `coin[q]_W_0`은 항상 `1`이라는 것을 알 수 있다. 따라서 `coin[0] = 2, coin[0]_W_0 = coin[0]_W_2 = 1` 이라는 것을 유추 할 수 있다. 한번더 유추를 하자면 `coin[0]_W_1 = coin[0]_W_3 = 0`이라는 것 또한 유추할 수 있다. 이 두가지를 유추했다면 이제 처음에 유추한 `coin[q]_W_0 = 1`이라는 것과 합쳐서 문제를 풀면 된다. 
