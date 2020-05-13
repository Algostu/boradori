#include <iostream>

int main()
{
	    int count = 0;
		    std::cin >> count;

			    for (int i = 0; i < count; i++)
					    {
							        for (int j = 0; j < i; j++)
										            std::cout << " ";

									        for (int k = 2 * (count - i - 1); k >= 0; k--)
												            std::cout << "*";

											        std::cout << std::endl;
													    }

				    for (int i = 2; i <= count; i++)
						    {

								        for (int j = 1; j <= count - i; j++)
											            std::cout << " ";

										        for (int k = 0; k <= 2 * (i - 1); k++)
													            std::cout << "*";

												        std::cout << std::endl;
														    }
}
