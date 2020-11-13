class Rational
{
    private:
        int numerator;
        int denominator;
    public:
        /* 
         * method to get numerator and denominator
         */
        int const n() const { int const a = numerator; return a; }
        int const d() const { int const b = denominator; return b; }
        Rational(int, int);
        Rational(const Rational&);
        int lcm(int, int);
        int gcd(int, int);
        void show();

        Rational operator + (Rational &t)
        {
            int y = lcm(denominator, t.d());
            int x = y / denominator * numerator + y / t.d() * t.n();
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
            int y = lcm(denominator, t.d());
            int x = y / denominator * numerator - y / t.d() * t.n();
            int tx = gcd(x, y);
            if (tx > 1 || tx < -1)
            {
                x /= tx;
                y /= tx;
            }
            Rational temp{x, y};
            return temp;
        }

        Rational operator * (Rational &t)
        {
            int x = numerator * t.n();
            int y = denominator * t.d();
            int tx = gcd(x, y);
            if (tx > 1 || tx < -1)
            {
                x /= tx;
                y /= tx;
            }
            Rational temp{x, y};
            return temp;
        }

        Rational operator / (Rational &t)
        {
            int x = numerator * t.d();
            int y = denominator * t.n();
            int tx = gcd(x, y);
            if (tx > 1 || tx < -1)
            {
                x /= tx;
                y /= tx;
            }
            Rational temp{x, y};
            return temp;
        }

        Rational operator = (const Rational &t)
        {
            this->numerator = t.n();
            this->denominator = t.d();
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
    numerator = t.n();
    denominator = t.d();
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
    cout << numerator << "/" << denominator << "  小数形式: " << 1.0 * numerator/denominator << endl;
}
