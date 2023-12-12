#include <iostream>
using namespace std;

class complex
{
public:
    double real, img; // Changed int to double

    // Constructor with default values
    complex(double r = 0, double i = 0)
    { // Changed int to double
        real = r;
        img = i;
    }

    complex operator+(complex obj)
    {
        complex c1;
        c1.real = real + obj.real;
        c1.img = img + obj.img;
        return c1;
    }
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i  <--- this is the formula for the multiplication of the complex nums
    complex operator*(complex obj)
    {
        complex c;
        double resReal = (real * obj.real) - (img * obj.img); // Changed int to double
        double resImg = (real * obj.img) + (img * obj.real);  // Changed int to double
        return complex(resReal, resImg);
    }

    void result()
    {
        cout << real << "+i" << img << "\n";
    }
};

int main()
{
    complex comp1(3.0, 2.0), comp2(1.0, 4.0); // Using double values
    complex comp3;
    complex comp4 = comp1 * comp2;
    comp3 = comp1 + comp2;
    comp3.result();
    comp4.result();
    return 0;
}
