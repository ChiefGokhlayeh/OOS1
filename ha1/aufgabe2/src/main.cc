#include <cmath>
#include <iostream>

using namespace std;

int basis, exponent;

int main(void) {
    cout << endl << "Basis = ";
    cin >> basis;
    cout << endl << "Exponent = ";
    cin >> exponent;
    cout << endl << "Ergebnis: " << endl;
    cout << endl << basis << "^" << exponent << " = "
        << pow(basis, exponent) << endl;
    return 0;
}