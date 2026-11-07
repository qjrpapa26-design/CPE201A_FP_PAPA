#include <iostream>
#include <iomanip>   
#include <cmath>     

using namespace std;


double hypotenuse(double, double);

int main()
{
    // The three right triangles to test (side1, side2).
    double side1[3] = {3.0, 5.0, 8.0};
    double side2[3] = {4.0, 12.0, 15.0};

    cout << fixed << setprecision(1);
    cout << setw(10) << "Triangle" << setw(10) << "Side 1"
         << setw(10) << "Side 2" << setw(15) << "Hypotenuse" << endl;

    // Call the function once for each triangle.
    for (int i = 0; i < 3; i++)
    {
        cout << setw(10) << (i + 1)
             << setw(10) << side1[i]
             << setw(10) << side2[i]
             << setw(15) << hypotenuse(side1[i], side2[i]) << endl;
    }

    return 0;
}

// Pythagorean theorem: c = sqrt(a^2 + b^2)
double hypotenuse(double a, double b)
{
    return sqrt(pow(a, 2) + pow(b, 2));   // pow and sqrt from <cmath>
}
