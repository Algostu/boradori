#include <iostream>
using namespace std;

class Star
{
private:
    string a, b, c;

public:
    Star(string a, string b, string c) : a(a), b(b), c(c){}
    ~Star() {}
    void Upgrade()
    {   
        for (int i = 1; i < 3; i++)
        {
            a += a;
        }
        for (int i = 1; i < 3; i++)
        {   
            if (i == 1)
            {
                int temp = b.size();
                for (int j = 0; j < temp; j++)
                {
                    cout << "D";
                    b += " ";
                }
            }
            else
                b += b;
        }
        for (int i = 1; i < 3; i++)
        {
            c += c;
        }
    }

    friend ostream &operator<<(ostream &os, Star &s);
};

ostream &operator<<(ostream &os, Star &s)
{
    for (int i = 0; i < 3; i++)
    {
        os << s.a;
    }
    os << endl;
    for (int i = 0; i < 3; i++)
    {
            os << s.b;
    }
    os << endl;
    for (int i = 0; i < 3; i++)
    {
        os << s.c;
    }
    os << endl;
    return os;
}

int main()
{
    Star stars("*", "*", "*");
    int n;
    string a;

    cin >> n;
    cout << stars;
    cout << "==================" << endl;
    stars.Upgrade();
    cout << stars;
    cout << "==============" << endl;
    stars.Upgrade();
    cout << stars;
    

    return 0;
}