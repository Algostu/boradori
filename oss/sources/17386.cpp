#include <iostream>
#include <cmath>

struct Vector2
{
	public:
		Vector2(long x, long y) :
			mX(x),
			mY(y)
		{}

		long Cross(const Vector2& other) const 
		{
			return mX * other.mY - mY * other.mX;
		}

		Vector2 operator - (const Vector2& other) const 
		{
			return Vector2(mX - other.mX, mY - other.mY);
		}

		bool operator == (const Vector2& other) const
		{
			return mX == other.mX && mY == other.mY;
		}

		bool operator < (const Vector2& other) const
		{
			return mX < other.mX && mY < other.mY;
		}

		long GetX() const {
			return mX;
		}

		long GetY() const {
			return mY;
		}

	private:
		long mX;
		long mY;

};

long CCW(Vector2 lhs, Vector2 rhs)
{
	return lhs.Cross(rhs);
}

long CCW(Vector2 p, Vector2 lhs, Vector2 rhs)
{
	//return CCW(lhs - p, rhs - p);
	long temp = p.GetX() * lhs.GetY() + lhs.GetX() * rhs.GetY() + rhs.GetX() * p.GetY();
	temp = temp - p.GetY() * lhs.GetX() - lhs.GetY() * rhs.GetX() - rhs.GetY() * p.GetX();

	if (temp > 0) return 1;
	else if (temp == 0) return 0;
	else if (temp < 0) return -1;
}

bool Solution(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
	long e = CCW(a, b, c) * CCW(a, b, d);
	long f = CCW(c, d, a) * CCW(c, d, b);

	if (e == 0 && f == 0)
	{
		if (b < a) std::swap(a, b);
		if (d < c) std::swap(c, d);
		
		return !(b < c || d < a);
	}

	return e <= 0 && f <= 0;
}

int main()
{
	long x1, y1, x2, y2, x3, y3, x4, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	Vector2 a(x1, y1);
	Vector2 b(x2, y2);
	Vector2 c(x3, y3);
	Vector2 d(x4, y4);

	if (Solution(a, b, c, d))
		std::cout << 1 << std::endl;
	else
		std::cout << 0 << std::endl;

	return 0;
}
