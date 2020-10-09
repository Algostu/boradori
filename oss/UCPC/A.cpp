#include <iostream>

int main()
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int x = (c * e - b * f) / (a * e - b * d);
    int y = (a * f - c * d) / (a * e - b * d);

    std::cout << x << " " << y << std::endl;

    return 0;
}