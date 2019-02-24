unsigned int NOD(unsigned int a, unsigned int b)
{
    while(b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int NOK (int a, int b)
{
    return a * b / NOD (a, b);
}

class Rational
{
public:
    Rational()
    {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator)
    {
        if(denominator == 0)
        {
            throw invalid_argument("Denominator is equal to zero!");
        }
        int tmp = NOD(abs(numerator), abs(denominator));
        p = denominator > 0 ? numerator / tmp : -numerator / tmp;
        q = denominator > 0 ? denominator / tmp : -denominator / tmp;
    }

    int Numerator() const
    {
        return p;
    }

    int Denominator() const
    {
        return q;
    }

private:
    int p;
    int q;
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator() ? true : false;
}

bool operator < (const Rational& lhs, const Rational& rhs)
{
    int tmp = NOK(lhs.Denominator(), rhs.Denominator());
    return lhs.Numerator() * tmp / lhs.Denominator() < rhs.Numerator() * tmp / rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
    int tmp = NOK(lhs.Denominator(), rhs.Denominator());
    return {lhs.Numerator() * tmp / lhs.Denominator() + rhs.Numerator() * tmp / rhs.Denominator(), tmp};
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
    int tmp = NOK(lhs.Denominator(), rhs.Denominator());
    return {lhs.Numerator() * tmp / lhs.Denominator() - rhs.Numerator() * tmp / rhs.Denominator(), tmp};
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
    if(rhs.Numerator() == 0)
    {
        throw domain_error("Impossible to divide by zero!");
    }
    int tmp = NOK(rhs.Numerator(), rhs.Denominator());
    return {lhs.Numerator() * tmp / rhs.Numerator(), lhs.Denominator() * tmp / rhs.Denominator()};
}

istream& operator >> (istream& s, Rational& r)
{
    if(s.good())
    {
        int a, b;
        s >> a;
        s.ignore(1);
        s >> b;
        r = {a, b};
    }
    return s;
}

ostream& operator << (ostream& s, const Rational& r)
{
    s << r.Numerator() << '/' << r.Denominator();
    return s;
}
