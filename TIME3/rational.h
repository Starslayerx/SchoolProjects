class Rational
{
    public:
        int numerator;
        int denominator;
        Rational(int, int);
        Rational(const Rational&);
        int lcm(int, int);
        int gcd(int, int);
        void show();

        Rational operator + (Rational &t)
        {
            int y = lcm(denominator, t.denominator);
            int x = y / denominator * numerator + y / t.denominator *t.numerator;
            int tx = gcd(x, y);
            if (tx > 1 || tx < -1)
            {
                x /= tx;
                y /= tx;
            }
            Rational temp{x, y};
            return temp;
        }

        Rational operator - (Rational &t)
        {
            int y = lcm(denominator, t.denominator);
            int x = y / denominator * numerator - y / t.denominator *t.numerator;
            int tx = gcd(x, y);
            if (tx > 1 || tx < -1)
            {
                x /= tx;
                y /= tx;
            }
            Rational temp{x, y};
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
            numerator = t.numerator;
            denominator = t.denominator;
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
    numerator = a;
    denominator = b;
}
Rational::Rational(const Rational &t)
{
    numerator = t.numerator;
    denominator = t.denominator;
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
    if (!numerator)
    {
        cout << 0 << endl;
        return;
    }
    cout << numerator << "/" << denominator << endl;
}
