#include <iostream>
#include <cmath>
#include <string>

int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b;
        std::cin >> a >> b;
        int c = a * pow(10, b);

        int v = trunc(log10(c)) + 1;

        int answer = c % (v + 1);
    }

    return 0;
}