#include <iostream>

int main()
{
	int testCases;
	std::cin >> testCases;
	
	for (int testCase = 0; testCase < testCases; testCase++)
	{
		int studentCount;
		std::cin >> studentCount;

		float totalScore = 0;
		float scores[studentCount] = { 0 };
		for (int studentIndex = 0; studentIndex < studentCount; studentIndex++)
		{
			std::cin >> scores[studentIndex];
			totalScore += scores[studentIndex];
		}

		float average = totalScore / studentCount;
		float overAverageStudentCount = 0;
		
		for (int studentIndex = 0; studentIndex < studentCount; studentIndex++)
		{
			if (scores[studentIndex] > average) overAverageStudentCount++;
		}

		std::cout.precision(3);
		std::cout << std::fixed << overAverageStudentCount / studentCount * 100 << "%" << std::endl;
	}

	return 0;
}
