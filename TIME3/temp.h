class Rational
{
    public:
        int denominator;
        int numerator;
        Rational(int, int);
        Rational(const Rational&);
        int lcm(int, int);
        int gcd(int, int);
        void show();

        Rational operator + (Rational &t)
        {
            Rational temp{1, 1};
            temp.numerator = lcm(numerator, t.numerator);
            temp.denominator = temp.numerator / numerator * t.denominator + temp.numerator / t.numerator * denominator;
            int t = gcd(a, b);
            if (t > 1 || t < -1)
            {
                a /= t;
                b /= t;
            }
            return temp;
        }
        Rational operator - (Rational &t)
        {
            Rational temp{1, 1};
            temp.numerator = lcm(numerator, t.numerator);
            temp.denominator = temp.numerator / numerator * t.denominator - temp.numerator / t.numerator * denominator;
            int t = gcd(a, b);
            if (t > 1 || t < -1)
            {
                a /= t;
                b /= t;
            }
            return temp;
        }
        /*
        Rational operator * (Rational &t)
        {
            Rational temp{1, 1};
        }
        */

        Rational operator = (Rational &t)
        {
            denominator = t.denominator;
            numerator = t.numerator;
            return *this;
        }
};

Rational::Rational(int a, int b)
{
    int t = gcd(a, b);
    if (t > 1 || t < -1)
    {
        a /= t;
        b /= t;
    }
    if (b == 0)
    {
        cout << "Numerator can't be 0 !" << endl;
        return;
    }
    denominator = a;
    numerator = b;
}
Rational::Rational(const Rational &t)
{
    denominator = t.denominator;
    numerator = t.numerator;
}
int Rational::gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int Rational::lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
void Rational::show()
{
    if (!denominator)
    {
        cout << 0 << endl;
        return;
    }
    cout << denominator << "/" << numerator << endl;
}
