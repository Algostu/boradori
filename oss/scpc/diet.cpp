//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	int TestCase;
//	std::cin >> TestCase;
//
//	for (int testCase = 0; testCase < TestCase; testCase++)
//	{
//		int n, k;
//		std::cin >> n >> k;
//
//		std::vector<int> aMenu(n);
//		aMenu.clear();
//
//		std::vector<int> bMenu(n);
//		bMenu.clear();
//
//		for (int i = 0; i < n; i++)
//		{
//			int kalori = 0;
//			std::cin >> kalori;
//
//			aMenu.push_back(kalori);
//		}
//	
//		for (int i = 0; i < n; i++)
//		{
//			int kalori = 0;
//			std::cin >> kalori;
//
//			bMenu.push_back(kalori);
//		}
//
//		std::sort(aMenu.begin(), aMenu.end());
//		std::sort(bMenu.begin(), bMenu.end(), std::greater<>());
//
//		for (int i = 0; i < n - k; i++)
//		{
//			aMenu.erase(aMenu.end() - 1);
//			bMenu.erase(bMenu.begin());
//		}
//
//		std::vector<int> totalKalori(n);
//		totalKalori.clear();
//
//		for (int i = 0; i < n; i++)
//		{
//			totalKalori.push_back(aMenu[i] + bMenu[i]);
//		}
//		std::sort(totalKalori.begin(), totalKalori.end());
//
//		int answer = totalKalori[k - 1];
//		
//		std::cout << "Case #" << testCase + 1 << std::endl << answer << std::endl;
//	}
//
//	return 0;
//}

/*
   You should use the standard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful. 
   */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
		int T, test_case;
			/*
				   The freopen function below opens input.txt file in read only mode, and afterward,
					   the program will read from input.txt file instead of standard(keyboard) input.
						   To test your program, you may save input data in input.txt file,
							   and use freopen function to read from the file when using cin function.
								   You may remove the comment symbols(//) in the below statement and use it.
									   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
										   But before submission, you must remove the freopen function or rewrite comment symbols(//).
											 */	

			// freopen("input.txt", "r", stdin);

			cin >> T;
				for(test_case = 0; test_case  < T; test_case++)
						{

									Answer = 0;
											/////////////////////////////////////////////////////////////////////////////////////////////
											/*
													   Implement your algorithm here.
															   The answer to the case will be stored in variable Answer.
																	 */
											/////////////////////////////////////////////////////////////////////////////////////////////
										       int n, k;
											           std::cin >> n >> k;

													           std::vector<int> aMenu(n);
															           aMenu.clear();

																	           std::vector<int> bMenu(n);
																			           bMenu.clear();

																					           for (int i = 0; i < n; i++)
																								           {
																											               int kalori = 0;
																														               std::cin >> kalori;

																																	               aMenu.push_back(kalori);
																																				           }

																							           for (int i = 0; i < n; i++)
																										           {
																													               int kalori = 0;
																																               std::cin >> kalori;

																																			               bMenu.push_back(kalori);
																																						           }

																									           std::sort(aMenu.begin(), aMenu.end());
																											           std::sort(bMenu.begin(), bMenu.end(), std::greater<>());

																													           for (int i = 0; i < n - k; i++)
																																           {
																																			               aMenu.erase(aMenu.end() - 1);
																																						               bMenu.erase(bMenu.begin());
																																									           }

																															           std::vector<int> totalKalori(n);
																																	           totalKalori.clear();


																																			           for (int i = 0; i < n; i++)
																																						           {
																																									               totalKalori.push_back(aMenu[i] + bMenu[i]);
																																												           }
																																					           std::sort(totalKalori.begin(), totalKalori.end());

																																							           Answer = totalKalori[k - 1];
																																											
																																											// Print the answer to standard output(screen).
																																											cout << "Case #" << test_case+1 << endl;
																																													cout << Answer << endl;
																																														}

					return 0;//Your program should return 0 on normal termination.
}
