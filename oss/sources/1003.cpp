#include <iostream>
#include <utility>

#define __linux__
#define __x86_64__

template <class T, class I>
struct Pair
{
	public:
		Pair(const T first, const I second) : mFirst(first), mSecond(second) { }
		Pair() : mFirst(0), mSecond(0) { }

		Pair<T, I> operator + (const Pair<T, I>& rhs) 
		{
			return Pair<T, I>(mFirst + rhs.mFirst, mSecond + rhs.mSecond);
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<T, I> pair)
		{
			os << pair.mFirst << " " << pair.mSecond;
			return os;
		}
		
	public:
		T mFirst;
		I mSecond;
};

Pair<unsigned int, unsigned int> numbers[41];

Pair<unsigned int, unsigned int> Fabonachi(unsigned int n)
{
	if (n == 0)
	{
		return Pair<unsigned int, unsigned int>(1, 0);
	}
	else if (n == 1)
	{
		return Pair<unsigned int, unsigned int>(0, 1);
	}
	else if (numbers[n].mFirst != 0 || numbers[n].mSecond != 0)
	{
		return numbers[n];
	}
	else	
	{
		numbers[n] = Fabonachi(n - 1) + Fabonachi(n - 2);

		return 	numbers[n];
	}
}

int main()
{
	unsigned int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		unsigned int k = 0;
		std::cin >> k;
		
		std::cout << Fabonachi(k) << std::endl;
	}
	return 0;
}
