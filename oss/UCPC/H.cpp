#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int twoCount = 0;
    int oneCount = 0;
    
    for (int i = 0; i < N; i++)
    {
        int height;
        std::cin >> height;

        twoCount += height / 2;
        oneCount += height % 2;
    }

    if ((oneCount <= twoCount) && (twoCount - oneCount) % 3 == 0 /* && (twoCount - oneCount) / 3 >= 0 */)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}