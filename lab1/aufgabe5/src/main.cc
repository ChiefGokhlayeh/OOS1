#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

double trapezFlaeche(double a, double b = -1, double phi = M_PI / 2, double c = -1)
{
    if (b < 0) {
        b = a;
    }
    if (c < 0) {
        c = a;
    }
    return 0.5 * (a + c) * b * sin(phi);
}

int main()
{
    srand(time(nullptr));
    double a, b, c, phi;
    a = (double(rand()) / RAND_MAX) * 2.0;
    b = (double(rand()) / RAND_MAX) * 2.0;
    c = (double(rand()) / RAND_MAX) * 2.0;
    phi = M_PI / max(4.0, min(double(rand()), 0.1));

    cout << fixed;
    cout.precision(3);

    double flaeche = trapezFlaeche(a, b, phi, c);
    cout << "Fläche von Trapez {a=" << a << " b=" << b << " c=" << c << " phi=" << phi << "} ist " << flaeche << endl;

    flaeche = trapezFlaeche(a, b, phi);
    cout << "Fläche von Parallelogram {a=" << a << " b=" << b << " phi=" << phi << "} ist " << flaeche << endl;

    flaeche = trapezFlaeche(a, b);
    cout << "Fläche von Rechteck {a=" << a << " b=" << b << "} ist " << flaeche << endl;

    flaeche = trapezFlaeche(a);
    cout << "Fläche von Quadrat {a=" << a << "} ist " << flaeche << endl;

    return 0;
}
