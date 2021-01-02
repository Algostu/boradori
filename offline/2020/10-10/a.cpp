#include <algorithm>
#include <chrono>
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

class point
{
 public:
    int x;
    int y;
    int y_idx;
    bool checked;
    point(int x, int y) : x(x), y(y)
    {
    }

    float getDistance(point* p)
    {
        return sqrt(pow((p->x - x), 2) + pow((p->y - y), 2));
    }
};

int N;
point* cur_p;
vector<point*> x_axis, y_axis;

bool x_compare(point* a, point* b)
{
    return a->x < b->x;
}

bool y_compare(point* a, point* b)
{
    return a->y < b->y;
}

void getMinimumDistance(int cur_i, float& min_distance, int direction)
{
    int i = (direction == 1 ? cur_i + 2 : cur_i - 1);
    bool flag_x, flag_y;
    while ((direction == 1 ? i < N : i >= 0) &&
           (flag_x = ((x_axis[i]->x - cur_p->x) < min_distance)))
    {
        if (flag_x && x_axis[i]->checked != true)
        {
            float cur_distance = cur_p->getDistance(x_axis[i]);
            if (min_distance > cur_distance)
            {
                min_distance = cur_distance;
            }
        }
        direction == 1 ? i++ : i--;
    }

    i = (direction == 1 ? x_axis[cur_i]->y_idx + 1 : x_axis[cur_i]->y_idx - 1);
    while ((direction == 1 ? i < N : i >= 0) &&
           (flag_y = ((y_axis[i]->x - cur_p->x) < min_distance)))
    {
        if (flag_y && y_axis[i]->checked != true)
        {
            float cur_distance = cur_p->getDistance(y_axis[i]);
            if (min_distance > cur_distance)
            {
                min_distance = cur_distance;
            }
        }
        direction == 1 ? i++ : i--;
    }
}

void solve(int test_num = 0)
{
    vector<point*> point_arr;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        point_arr.push_back(new point(x, y));
        x_axis.push_back(point_arr[i]);
        y_axis.push_back(point_arr[i]);
    }
    sort(x_axis.begin(), x_axis.end(), x_compare);
    sort(y_axis.begin(), y_axis.end(), y_compare);
    for (size_t i = 0; i < N; i++)
    {
        y_axis[i]->y_idx = i;
    }

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();
    for (size_t x_i = 0; x_i < N - 1; x_i++)
    {
        cur_p = point_arr[x_i];
        cur_p->checked = true;
        float min_distance = cur_p->getDistance(point_arr[x_i + 1]);
        // cout << "minimun distacne : " << min_distance << endl;
        getMinimumDistance(x_i, min_distance, 1);
        getMinimumDistance(x_i, min_distance, 0);
        cur_p->checked = false;
        // printf("x : %d y : %d changed minimun distacne : %f\n", cur_p->x,
        // cur_p->y, min_distance);
    }
    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "Time difference = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                       begin)
                     .count()
              << "[ms]" << std::endl;
    std::cout << "Time difference = "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                      begin)
                     .count()
              << "[ns]" << std::endl;
}

int main(void)
{
    freopen("../input.txt", "r", stdin);
    solve();
}
