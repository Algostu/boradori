#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

int main()
{
    int n, m;
    std::cin >> n >> m;    

    std::unordered_map<char, char> rotateChar;
    
    rotateChar.clear();

    rotateChar['.'] = '.';
    rotateChar['O'] = '0';
    rotateChar['-'] = '|';
    rotateChar['|'] = '-';
    rotateChar['/'] = '\\';
    rotateChar['\\'] = '/';
    rotateChar['^'] = '<';
    rotateChar['<'] = 'v';
    rotateChar['v'] = '>';
    rotateChar['>'] = '^';                            

    char chars[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> chars[i][j];
        }
    }

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << rotateChar[chars[i][j]];
        }

        std::cout << '\n';
    }

    return 0;
}