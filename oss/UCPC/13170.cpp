#include <iostream>
#include <cmath>

int main()
{
    double n, k, p, w;
    std::cin >> n >> k >> p >> w;

    std::cout << static_cast<int>(ceil(p / w)) << std::endl;

    return 0;
}