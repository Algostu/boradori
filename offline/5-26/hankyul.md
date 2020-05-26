## 05.23일날 두번째로 풀었던 문제

1. **문제 설명**  
문제 출처 : [백준 17143](https://www.acmicpc.net/problem/17143)

상어를 낚아보자! 낚시꾼이 걸어가면서 자기 발 밑에 있는 상어중 가장 가까운 상어를 낚는다. 낚시꾼이 낚은 상어의 크기의 합은 얼마나 될까? 낚시꾼은 참 착하게 1초에 한걸음씩만 움직인다. 그리고 자신의 발 밑에 있는 상어를 잡는다. 이때 상어는 멍청하게 낚시꾼이 한번 낚시를 하고 나서 움직인다. 이 문제의 핵심은 한가지이다. 상어가 어떻게 움직일 것인가.  

상어의 움직임을 계산하는것은 크게 두개의 부분으로 나눌 수 있다. 첫번째는 상어의 움직임의 속도가 `R`을 넘어가는가 이다. 만약 넘는다면 상어의 위치를 계산할때 움직임을 부분적으로 나눠서 계산해야한다. 먼저 `S/R`이 홀수 인 경우다. 즉, 몫이 홀수인 경우에 상어는 반대편으로 이동한다고 생각하면 된다. 이를 쉬운 파이썬 코드로 나타내면 다음과 같다.
``` python
if (S/R) & 1:
  shark = R - shark
```

이건 어려운 버전
```c
// update where
switch(shark->d){
  case 1:
    if((shark->s / (R-1)) & 1) {shark->r = (R-1) - shark->r; shark->d = 2;}
    break;

  case 2:
    if((shark->s / (R-1)) & 1) {shark->r = (R-1) - shark->r; shark->d = 1;}
    break;

  case 4:
    if((shark->s / (C-1)) & 1) {shark->c = (C-1) - shark->c; shark->d = 3;
    //printf("z : %d c : %d \n",shark->z, shark->c);}
    }
    break;

  case 3:
    if((shark->s / (C-1)) & 1) {shark->c = (C-1) - shark->c; shark->d = 4;
    //printf("z : %d c : %d \n",shark->z, shark->c);}
    }
    break;
}
```

다음으로는 상어가 움직일때 벽에 한번 닫는 경우다. 이 경우에는 상어의 움직임이 바뀌므로 상어가 바뀐 방향으로 이동하게끔 계산해주는 것이 중요하다. 이 또한 코드로 나타내면 다음과 같다.

```c
switch(shark->d){
  case 1:
    temp = shark->s % (R-1);
    if(r-temp > 0) shark->r = r-temp;
    else { shark->r = temp - r; shark->d = 2; }
    break;

  case 2:
    temp = shark->s % (R-1);
    if(r+temp < R) shark->r = r+temp;
    else { shark->r = 2 * (R-1) - (r + temp); shark->d = 1; }
    break;

  //left
  case 4:
    temp = shark->s % (C-1);
    if(c-temp > 0) shark->c = c-temp;
    else { shark->c = temp - c; shark->d = 3; }
    //printf("z : %d c : %d temp : %d\n",shark->z, shark->c, temp);
    break;

  // right
  case 3:
    temp = shark->s % (C-1);
    if(shark->c+temp < C) shark->c = shark->c+temp;
    else { shark->c = 2 * (C-1) - (c + temp); shark->d = 4; }
    //printf("z : %d c : %d temp : %d\n",shark->z, shark->c, temp);
    break;
}
```

2. 사용법

백준 문제이기 때문에 사용법이 따로 없습니다.
