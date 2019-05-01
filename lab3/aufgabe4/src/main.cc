#include <iostream>
#include "circle3.hh"
#include "polygon3.hh"

using namespace std;

int main(void)
{
    string str1("(1.1,2.1)");
    string str2("<(5.5, 6.6), 10.1>");
    string str3("|(1.1,1.2) - (2.1, 2.2) -(3.1,3.2) |");
    Point p(str1);
    Circle c(str2);
    Polygon l(str3);

    cout << p << endl;
    cout << c << endl;
    c.Move(1.0, 2.0);
    cout << c << endl;
    cout << l << endl;
    return 0;
}
