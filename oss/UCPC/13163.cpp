#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;
    
    while (n > 0)
    {
        std::string name;
        std::getline(std::cin, name);

        if (name.length() == 0)
        {
            // n--;
            continue;
        }

        int index = 0;
        for (; index < name.length(); index++)
        {
            if (name[index] == ' ') break;
        }

        std::string newName = "god";
        for (int i = index + 1; i < name.size(); i++)
        {
            if (name[i] == ' ') continue;
            newName.insert(newName.end(), name[i]);
        }

        std::cout << newName << std::endl;

        n--;
    }
}