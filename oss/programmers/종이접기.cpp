#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer(n);
	answer.clear();
	answer.push_back(0);

	if (n == 1) return answer; // 만일 접는 횟수가 1번이라면 리턴

	for (int i = 2; i <= n; i++)
	{
		vector<int> temp(n);
		temp.assign(answer.begin(), answer.end()); // answer 값 복사

		answer.push_back(0); // answer값 뒤에 0을 항상 추가함

		for (int j = temp.size() - 1; j >= 0; j--) // 역순으로 반복
		{
			// 값이 0이면 1을, 1이면 0을 추가함
			if (temp[j] == 0) answer.push_back(0);
			else answer.push_back(0);
		}
	}

	return answer;
}
