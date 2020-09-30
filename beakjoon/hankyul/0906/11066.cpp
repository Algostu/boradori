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

#define MAX_FILES 500
#define MAX_COST 1000000000

using namespace std;

// files[i][j] = min( files[i][k] + files[k+1][j] ) + sum[j] - sum[i] ( k = i+1
// ~ j-1 )

int find_smallest_file_sum(list<int>& files)
{
    int min = MAX_COST;
    list<int>::iterator minIndex;
    for (list<int>::iterator iter = files.begin(); iter != files.end();)
    {
        int sum = *iter;
        cout << sum << " ";
        iter++;
        if (iter == files.end())
            break;
        sum += *iter;
        if (min > sum)
        {
            min = sum;
            minIndex = --iter;
            iter++;
        }
    }
    cout << ":";
    minIndex = files.erase(minIndex);
    files.insert(minIndex, min);
    files.erase(minIndex);

    cout << min << endl;
    return min;
}

void solve(int test_num = 0)
{
    int K, sum = 0;
    list<int> files;
    scanf("%d", &K);
    for (size_t i = 0; i < K; i++)
    {
        int input;
        scanf("%d", &input);
        files.push_back(input);
    }
    for (size_t i = 0; i < K - 1; i++)
    {
        cout << "Step " << (i + 1)
             << "--------------------------------------\n";
        sum += find_smallest_file_sum(files);
    }

    printf("%d\n", sum);
}

int main(void)
{
    freopen("../input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }
}
