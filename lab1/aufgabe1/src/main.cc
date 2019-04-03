#include <string>
#include <ios>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double d = 1.234;
    int colWidth = 11;
    cout << showbase << setw(colWidth) << right << "Nr"
        << " "<< setw(colWidth) << right << "Oct"
        << " "<< setw(colWidth) << right << "Hex"
        << " " << setw(colWidth) << right << "String"
        << " "<< setw(colWidth) << right << "Fixed"
        << " "<< setw(colWidth) << right << "Scientific" << endl;
    cout << setprecision(3);
    for (int k = 0; k < 11; k++) {
        cout << setw(colWidth) << right << dec << k;
        cout << " " << setw(colWidth) << right << oct << k;
        cout << " " << setw(colWidth) << right << hex << k;
        cout.fill('+');
        cout << " " << setw(colWidth) << left << string(k % 5 + 1, '*');
        cout.fill(' ');
        cout << " " << setw(colWidth) << fixed << internal << showpos << d;
        cout << " " << setw(colWidth) << scientific << right << noshowpos << d;
        cout << endl;
        d *= -2;
    }

    return 0;
}
