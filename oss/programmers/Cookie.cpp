#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie)
{
	int answer = 0;

	vector<int> tempCookie = cookie;

	int brotherBucketCount = 1;
	int brotherCookieCount = 0;
	int olderBrotherCookieCount = 0;

	for (int i = 0; i < brotherBucketCount; i++)
	{
		int cookieCount = tempCookie[tempCookie.size() - i]; 
		brotherCookieCount += cookieCount;
	}

	for (int i = 0; i < tempCookie.size() - brotherBucketCount; i++)
	{
		olderBrotherCookieCount += tempCookie[i];
	}
	
	std::cout << brotherCookieCount << " " << olderBrotherCookieCount << std::endl;


	return answer;
}

int main()
{
	vector<int> cookie;
	cookie.clear();

	for (int i = 0; i < 4; i++)
	{
		int count;
		std::cin >> count;

		cookie.push_back(count);
	}

	solution(cookie);
	
	return 0;
}
