## 05.23일날 두번째로 풀었던 문제

1. **문제 설명**  
문제 출처 : [프로그래머스-2018 KAKAO BLIND RECRUITMENT](https://programmers.co.kr/learn/courses/30/lessons/17676)

이 문제는 주어진 문자열 배열에서 시간 정보를 추출해서 시간대로 정렬한 후에 겹치는 시간이 가장 많을때 최대로 겹치는 양이 얼마인가를 묻는 문제이다. 우선 문자열에서 시간 정보를 추출하는 것은 다음과 같은 코드로 구현했다. sscanf를 통해서 주어진 문자열에서 원하는 정보인 `hh:mm:ss.sss ss.sss` 를 추출한뒤 millisecond 단위로 바꿔서 logs 변수에 저장했다.

```c
for(i=0;i<lines.size();i++){
    sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%f %fs", &trash, &trash, &trash, &h, &m, &s, &duration);
    logs[i].end = s * 1000 + m * 60000 + h * 2400000;
    logs[i].start = logs[i].end - (int)round(duration*1000) + 1;
}
```

이런식으로 저장하고 난뒤에는 끝나는 순서대로 정렬되어있는 log들을 시작하는 순서로 재정렬할 필요가 있다. 이 때는 quicksort를 사용했다.

```c
qsort(logs, lines.size(), sizeof(my_time), comp);
```
마지막으로 정렬되어있는 로그들 중에서 겹치는 것을 찾아야 했는데 이 부분이 꽤나 까다로웠다. 하나의 로그의 시작과 에서 `시작시간 ~ 시작 시간+999 ` 혹은 `끝나는 시간 ~ 끝나는 시간+999` 라는 기준선을 만들고  기준선에 들어오는 다른 로그가 몇 개나 있는지 계산했다.

```c
for(j=0;j<lines.size();j++){
    if(logs[i].start > start+999) break;
    else if(logs[i].start < start && logs[i].end >= start) start_count++;
    else if (logs[i].start >= start && logs[i].start <= start+999) start_count++;
}

if(max < start_count) max = start_count;
``` 

2. 사용법

제가 cpp를 잘 몰라서 아시는 분이 좀 고쳐주세요~

```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int answer;
  char input_str[50][50];
  strcpy(input_str[0], "2016-09-15 20:02:22.222 2s");
  strcpy(input_str[1], "2016-09-15 20:02:24.222 0.2s");
  answer = solution(input_str);
  printf("answer : %d\n", answer);

  return 0;
}
```
