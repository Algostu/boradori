#include <iostream>
#include <cmath>

long long MiddelIndex(long long n, long long middle)
{
    long long index = 0;
    for (long long i = 1; i <= n; i++)
    {
        index += std::min(n, middle / i);
    }

    return index;
}

long long BinarySearch(long long n, long long target)
{
    long long first = 1;
    long long last = n * n;

    long long answer = 1;
    while (first <= last)
    {
        long long middle = (first + last) / 2;
        long long middelIndex = MiddelIndex(n, middle);

        if (middelIndex >= target)
        {
            answer = middle;
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    return answer;
}

int main()
{
    long long n = 0;
    std::cin >> n;

    long long k = 0;
    std::cin >> k;

    std::cout << BinarySearch(n, k) << std::endl;

    return 0;
}
