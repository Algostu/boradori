#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;

    unsigned long long q = n % 8;

    if ( q > 1 && q <= 5)
    {
        std::cout << q << std::endl;
        return 0;
    }

    switch (q)
    {
        case 6:
        {
            std::cout << 4 << std::endl;
        }
        break;
        case 7:
        {
            std::cout << 3 << std::endl;
        }
        break;
        case 0:
        {
            std::cout << 2 << std::endl;
        }
        break;
    }

    return 0;
}