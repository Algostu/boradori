#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Answer(int index, const std::vector<int>& money)
{
    if (index == 0)
    {
        return money[index];
    }
    else if (index == 1)
    {
        return money[index];
    }

    int answer = money[index] + money[index - 2];
    int answer1 = money[index] + money[index - 3];

    if (answer > answer1)
    {
        index += 2;
    }
    else
    {
        index += 3;
        answer = answer1;
    }
    
    return answer + Answer(index, money);
}

int solution(vector<int> money) {
    int answer0 = Answer(0, money);
    int answer1 = Answer(1, money);

    return answer0 > answer1 ? answer0 : answer1;
}

int main()
{
    std::vector<int> money;
    money.push_back(1);
    money.push_back(2);
    money.push_back(3);
    money.push_back(1);
    std::cout << solution(money) << std::endl;;

    return 0;
}