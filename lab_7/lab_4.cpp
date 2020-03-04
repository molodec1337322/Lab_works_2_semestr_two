#include <iostream>

using namespace std;

class Int
{
private:
    int i;

public:
    Int()
    {
        i = 0;
    }

    Int(int num)
    {
        i = num;
    }

    int GetVla() const
    {
        return i;
    }

    void ShowVal() const
    {
        cout << i;
    }

    void ThrowIntOverflow()
    {
        cout << "\nStack overflow";
        throw exception();
    }

    Int CheckInt(long double result)
    {
        if (result > 2147483648.0L || result < -2147483648.0L)
        {
            ThrowIntOverflow();
        }
        return Int(result);
    }

    Int operator+(Int i2)
    {
        return CheckInt((long double)i + (long double)i2.i);
    }

    Int operator-(Int i2)
    {
        return CheckInt((long double)i - (long double)i2.i);
    }

    Int operator*(Int i2)
    {
        return CheckInt((long double)i * (long double)i2.i);
    }

    Int operator/(Int i2)
    {
        return CheckInt((long double)i / (long double)i2.i);
    }
};

int main()
{
    Int alpha = 20;
    Int beta = 7;
    Int delta, gamma;

    gamma = alpha + beta; //27
    cout << "\ngamma="; gamma.ShowVal();

    gamma = alpha - beta; //13
    cout << "\ngamma="; gamma.ShowVal();

    gamma = alpha * beta; //140
    cout << "\ngamma="; gamma.ShowVal();

    gamma = alpha / beta; //2
    cout << "\ngamma="; gamma.ShowVal();

    delta = 2147483647;
    gamma = delta + alpha; //overflow error

    delta = -2147483647;
    gamma = delta - alpha; //overflow error
}
