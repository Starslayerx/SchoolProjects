class Shape
{
    public:
        double area(){return 0;}
        double grith() {return 0;}
        Shape() { cout << "Didn't initlize." << endl; }
        void show()
        {
            cout << "Shapde object" << endl;
        }
};

class Circle : public Shape
{
    private:
        double r, circle_area, circle_grith;
        static const double PI;
    public:
        Shape::Shape() {}
        Circle() { cout << "Didn't initlize." << endl; } 
        Circle(double a) : r{a}
        {
            if (r <= 0)
            {
                cout << "半径必须大于0" << endl;
                return;
            }
            circle_area = PI * r * r;
            circle_grith = PI * r * 2;
        }
        ~Circle(){};
        double area();
        double grith();
        void show();
};

class Triangle : public Shape
{
    private:
        double x, y, z, triangle_area, triangle_grith;
    public:
        Triangle() { cout << "Didn't initlize." << endl; }
        Triangle(double a, double b, double c) : x{a}, y{b}, z{c}
        {
            if( a <= 0 || b <= 0 || c <= 0)
            {
                cout << "三角形三边必须大于零" << endl << endl;
                return;
            }
            if(!test(x, y, z))
            {
                cout << "不能构成三角形" << endl << endl;
                return;
            }
            // 海伦公式求面积
            double p = (x + y + z) / 2.0;
            triangle_area = sqrt(p * (p-x) * (p-y) * (p-z));
            triangle_grith = x + y + z;
        }
        bool test(double&, double&, double&);
        void show();
};

class Retangle : public Shape
{
}

const double Circle::PI{3.14159};
double Circle::area()
{
    return circle_area;
}
double Circle::grith()
{
    return circle_grith;
}

void Circle::show()
{
    cout << "Circle Object: " << endl;
    cout << "Area: " << circle_area << endl;
    cout << "Grith: " << circle_grith << endl << endl;
}
void Triangle::show()
{
    cout << "Triangle Object: " << endl;
    cout << "Area: " << triangle_area << endl;
    cout << "Grith: " << triangle_grith << endl << endl;
}
bool Triangle::test(double &a, double &b, double &c)
{
    double small = a > b ? a : b;
    small = small > c ? small : c;
    double big = a > b ? a : b;
    big = big > c ? big : c;
    double mid = a + b + c - small - big;
    if (big - mid >= small || small + mid <= big)
        return false;
    return true;
}
