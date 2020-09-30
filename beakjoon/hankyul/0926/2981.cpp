#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solve(int test_num = 0)
{
    int N, minValue = 1000000000, minIndex;
    int input[100];
    vector<int> divider;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    sort(input, input + N);

    for (size_t i = 0; i < N - 1; i++)
    {
        if (abs(input[i] - input[i + 1]) < minValue)
        {
            minIndex = i;
            minValue = abs(input[i] - input[i + 1]);
        }
    }

    for (int i = 2; i * i <= minValue; i++)
    {
        if (minValue % i == 0)
        {
            divider.push_back(i);
            if (i * i < minValue)
            {
                divider.push_back(minValue / i);
            }
        }
    }
    divider.push_back(minValue);
    sort(divider.begin(), divider.end());

    for (auto div : divider)
    {
        if (div == 1)
            continue;
        bool flag = true;
        int rem = input[0] % div;
        for (size_t i = 1; i < N; i++)
        {
            if (input[i] % div != rem)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("%d ", div);
        }
    }
    printf("\n");
}

int main(void)
{
    // freopen("../input.txt", "r", stdin);
    solve();
}
