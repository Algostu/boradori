
# 05.12일날 1번째로 풀었던 문제 - 종이접기

## 문제 설명
문제 출처 : [프로그래머스-Summer/Winter Coding(2019)](https://programmers.co.kr/learn/courses/30/lessons/62049)

이 문제는 종이를 n번 접었다 폈을 때, 안쪽으로 접힌 부분과, 바깥쪽으로 접힌 부분의 순서를 구하는 문제이다. 

1. 종이를 접을 때 마다 기존의 접힌 부분 다음은 항상 안쪽으로 접히게 된다. 때문에 매 단계마다 기존 답 뒤에 0을 추가한다.
```c++
	while(접는 횟수)
	{
		‘’’
		answer.push_back(0);
		’’’
	}
```
2. 종이를 접으면 항상 쌍으로 접힌다. 안쪽으로 접힌 부분이 다시 접히면 바깥쪽으로 접힌 부분이 생긴다 따라서 0을 추가하기 전 답에서 각 값의 논리부정(NOT) 연산 값을 answer 뒤에 추가한다. 종이를 폈었을 때가 기준임으로 연산 순서는 역순으로 한다.
```c++
    for (int i = 2; i <= n; i++)
    {
	    ```
        vector<int> temp(n);
        temp.assign(answer.begin(), answer.end());
        
        for(int j = (int)temp.size() - 1; j >= 0; j--)
        {
            if(temp[j] == 0) answer.push_back(1);
            else answer.push_back(0);
        }
        ```
    }
```

## 전체 코드


```c++
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer(n);
    answer.clear();
    answer.push_back(0);
    
    if (n == 1) return answer;
    
    for (int i = 2; i <= n; i++)
    {
        vector<int> temp(n);
        temp.assign(answer.begin(), answer.end());
        
        answer.push_back(0);
        
        for(int j = (int)temp.size() - 1; j >= 0; j--)
        {
            if(temp[j] == 0) answer.push_back(1);
            else answer.push_back(0);
        }
    }
    
    
    return answer;
}
```
