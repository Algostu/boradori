#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

void FlipArray(std::vector<int>& array, int startIndex, int endIndex)
{
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();

	int sum = 0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		if (min > array[i]) min = array[i];
		if (max < array[i]) max = array[i];

		sum += array[i];
	}

	std::reverse(array.begin() + startIndex, array.begin() + endIndex + 1);

    std::cout << min << " " << max << " " << sum << '\n';
}

void ShiftArray(std::vector<int>& v, int startIndex, int endIndex, int shiftOffset)
{
    int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();

	int sum = 0;

	for (int i = startIndex - 1; i < endIndex; i++)
	{
		if (min > v[i]) min = v[i];
		if (max < v[i]) max = v[i];

		sum += v[i];
	}

    vector<int> vv;
    for (size_t i = startIndex-1; i < endIndex; i++)
    {
        vv.push_back(v[i]);
    } 
	if (shiftOffset > 0){
        shiftOffset = shiftOffset % vv.size();
        rotate(vv.rbegin(),vv.rbegin()+shiftOffset,vv.rend());
        copy(vv.begin(),vv.end(),v.begin()+startIndex-1);
    }
    else 
	{      
        shiftOffset = (-shiftOffset) % vv.size();
        rotate(vv.begin(),vv.begin()+shiftOffset,vv.end());
        copy(vv.begin(),vv.end(),v.begin()+startIndex-1);
	}
	std::cout << min << " " << max << " " << sum << '\n';
}

void PrintArray(std::vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> array(n);
	array.clear();

	for (int i = 0; i < n; i++) 
	{
		array.push_back(i + 1);
	}

	int q = 0;
	std::cin >> q;

	while (q > 0)
	{
		int question = 0;
		std::cin >> question;

		switch (question)
		{
			case 1:
				{
					int startIndex = 0;
					int endIndex = 0;

					std::cin >> startIndex;
					std::cin >> endIndex;
					FlipArray(array, startIndex - 1, endIndex - 1); 
				}
				break;
			case 2:
				{
					int startIndex = 0;
					int endIndex = 0;
					int shiftOffset = 0;

					std::cin >> startIndex;
					std::cin >> endIndex;
					std::cin >> shiftOffset;

					ShiftArray(array, startIndex, endIndex, shiftOffset);
				}
				break;
			case 3:
				{
					int n;
					std::cin >> n;
					std::cout << array[n - 1] << std::endl;
				}
				break;
			case 4:
				{
					int n = 0;
					std::cin >> n;
					for (int i = 0; i < array.size(); i++)
					{
						if (array[i] == n)
						{
							std::cout << i + 1 << std::endl;
							break;
						}
					}
				}
				break;
		}

		q--;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}