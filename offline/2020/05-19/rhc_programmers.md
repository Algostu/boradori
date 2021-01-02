## 05.19일 '쿠키 구입' 코딩테스트 연습
문제 출처 : [프로그래머스-Summer/Winter Coding(~2018)](https://programmers.co.kr/learn/courses/30/lessons/49995)

------

쿠키의 배열에서 `cookie[x]~cookie[y]` 와 `cookie[y+1]~cookie[z]`까지의 합이 같고 같은 합 중 최대값을 찾아내는 문제이다. 물론, 모든 경우의 수를 고려하여 배열에 넣고 비교하면 되지만 매우 비효율적이다.
> **여기서 주목할 점**은 어차피 두 명이 나눠가지는 지점은 `y`이므로, 나는 `pointer`(C에서의 포인터를 의미하지는 않는다.)를 잡아두고 값을 비교하려 한다.

```cpp
for (int i = 1; i < cookie.size(); i++)
{
    pointer = i; //pointer는 right_pointer를 의미한다.
    left_pointer = i-1;
    left = cookie[left_pointer];
    right = cookie[pointer];
```

`pointer`를 기점으로 좌측과 우측을 나누고 `left`의 합과 `right`의 합을 비교한다. 그래서 `left`가 크면 `right`의 쿠키바구니 갯수를 하나 더 늘려 비교하고 `right`가 더 크면 `left`의 쿠키바구니 갯수를 늘리며 `left`와 `right`의 값이 같아지는 때를 찾아 max에 저장한다. 그래서 `left_pointer`나 `pointer`가 배열의 끝에 도달할 때 까지 계속해서 비교한다.

```cpp
while(left_pointer >= 0 && pointer < cookie.size()){
    // printf("i : %d || Left : %d || Right : %d\n",i, left,right);
    if(left > right) {
        pointer++;
        right += cookie[pointer];
    }
    else if(left < right) {
        left_pointer--;
        left += cookie[left_pointer];
    }
    else{
        if(max<right) max = right;
        pointer++;
        left_pointer--;
        right += cookie[pointer];
        left += cookie[left_pointer];
    }
}
```

자세한 진행상황을 보고싶다면 **printf**주석을 풀어서 실행시켜보자.
