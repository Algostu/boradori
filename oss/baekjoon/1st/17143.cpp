#include <iostream>
#include <vector>

struct SharkInfo
{
	int r;
	int c;
	int s;
	int d;
	int z;

	SharkInfo(const int r, const int c, const int s, const int d, const int z)
	{
		this->r = r;
		this->c = c;
		this->s = s;
		this->d = d;
		this->z = z;
	}

	SharkInfo(const SharkInfo& other) :
		r(other.r),
		c(other.c),
		s(other.s),
		d(other.d),
		z(other.z)
	{
	}

	bool operator==(const SharkInfo rhs) const
	{
		return (r == rhs.r) && (c == rhs.c) && (s == rhs.s) && (d == rhs.d) && (z == rhs.z);
	}

	public :
	bool IsSamePosition(const SharkInfo otherSharkInfo) const
	{
		return (r == otherSharkInfo.r) && (c == otherSharkInfo.c);
	}

	bool IsBigger(const SharkInfo otherSharkInfo) const 
	{
		return (z > otherSharkInfo.z);
	}
};

int r;
int c;

void RemoveShark(std::vector<SharkInfo> sharkInfos)
{
	for (auto iterator = sharkInfos.begin(); iterator != sharkInfos.end(); iterator++)
	{
		std::vector<SharkInfo> samePositionShark;
		for (auto tempIterator = iterator; tempIterator != sharkInfos.end(); tempIterator++)
		{
			if (*iterator.IsSamePosition(*tempIterator)) samePositionShark.push_back(*tempIterator);
		}

		if (samePositionShark.size() > 0)
		{
			SharkInfo biggestShark = samePositionShark[0];
			for (SharkInfo sharkInfo : samePositionShark)
			{
				if (sharkInfo.IsBigger(biggestShark)) biggestShark = sharkInfo;
			}	
			for (SharkInfo sharkInfo : samePositionShark)
			{
				if (sharkInfo == biggestShark) continue;

				sharkInfos.remove(sharkInfo);
			}
		}
	}
}

void MoveShark(std::vector<SharkInfo> sharkInfos)
{
	for (SharkInfo sharkInfo : sharkInfos)
	{
		switch (sharkInfo.d)
		{
			case 1:
				{
					if (sharkInfo.r - sharkInfo.s < 0)
					{
						int leftSpeed = sharkInfo.s - sharkInfo.r;
						sharkInfo.r = 0 + leftSpeed;

						sharkInfo.d = 2;
					}
					else
					{
						sharkInfo.r -= sharkInfo.s;
					}
				}
				break;
			case 2:
				{
					if (sharkInfo.r + sharkInfo.s > r)
					{
						int leftSpeed = sharkInfo.s - sharkInfo.r;
						sharkInfo.r = r - leftSpeed;

						sharkInfo.d = 1;
					}
				}
				break;
			case 3:
				{
					if (sharkInfo.c + sharkInfo.s > c)
					{
						int leftSpeed = sharkInfo.s - sharkInfo.c;
						sharkInfo.c = c - leftSpeed;

						sharkInfo.d = 4;
					}
				}
				break;
			case 4:
				{
					if (sharkInfo.c - sharkInfo.s < 0)
					{
						int leftSpeed = sharkInfo.s - sharkInfo.c;
						sharkInfo.c = 0 + leftSpeed;

						sharkInfo.d = 3;
					}
				}
				break;
		}
	}

	RemoveShark(sharkInfos);
}

int main()
{
	int sharkCount;
	std::cin >> r >> c >> sharkCount;
	r -= 1;
	c -= 1;

	std::vector<SharkInfo> sharkInfos;
	for (int i = 0; i < sharkCount; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int r, c, s, d, z;
			std::cin >> r >> c >> s >> d >>z;

			sharkInfos.push_back(SharkInfo(r - 1, c - 1, s, d, z));
		}
	}

	return 0;
}
