## Binary Search

Binary Search란 원하는 탐색 구간을 두 부분으로 나눠서 탐색하는 기법을 뜻한다. 두 부분으로 나눠서 탐색을 하기 때문에 기본 탐색보다 탐색 속도가 빠르다. 

**Pros** : `O(log(n))`의 시간 복잡도를 가지고 있다.
**Cons** : 탐색하고자 하는 배열이 미리 정렬되어야 한다.

# 기본 코드
```python
while left < right:
	mid = (left + right) / 2
	if arr[mid] == target : break;
	else if arr[mid] > target : right = mid - 1
	else left = mid + 1
```

# 실전 문제 
이 문제는 [백준 - 수찾기](https://www.acmicpc.net/problem/1920) 문제 입니다. 풀려고 많이 노력했으나 풀지 못했습니다. 죄송합니다.

# 주의 사항
- Numerical Underflows / Overflows

`left+right / 2` 에서 overflows 발생 가능

- Handling of duplication items

중복된 원소를 어떤 식으로 처리할지 고민해봐야 한다.

- Recursive VS Non-recursive

위에서 구현을 Non-recursive하게 했다. 요즘은 스택으로 인한 오버헤드를 피하기 위해서 Non-recursive방식으로 하는 추세이다.

- Off-by-one errors

경계값 에러이다. 위 코드는 사실 경계값 error 를 포함하고 있다. `while left < right : ` 이 부분은 `{0, 1}`을 찾을 때 경계값 오류로 인해서 찾을 수 없다. 



