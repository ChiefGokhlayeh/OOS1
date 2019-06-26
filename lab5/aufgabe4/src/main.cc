#include "circle5.hh"
#include "polygon5.hh"
#include "rectangle.hh"

#include <iostream>
#include <sstream>
#include <istream>
#include <functional>
#include <map>

using namespace std;

bool debugConstructor = true;

// lab5/aufgabe4/app_lab5_aufgabe4
int main(void)
{
    DrawingObject *objects[20];
    size_t anzahl = 0;
    cout << "Wie viele Objekte wollen sie einlesen?" << endl
         << "Anzahl: ";
    cin >> anzahl;

    if (anzahl > 20)
    {
        cerr << "Maximal 20 Objekte erlaubt!" << endl;
        return 1;
    }

    map<char, function<DrawingObject *(istream &)>> converters{
        {'(', [](istream &is) {
             auto *x = new Point();
             is >> *x;
             return x;
         }},
        {'<', [](istream &is) {
             auto *x = new Circle();
             is >> *x;
             return x;
         }},
        {'{', [](istream &is) {
             auto *x = new Polygon();
             is >> *x;
             return x;
         }},
        {'[', [](istream &is) {
             auto *x = new Rectangle();
             is >> *x;
             return x;
         }},
    };

    // Objekte einlesen
    for (int i = 0; i < anzahl; i++)
    {
        string s;
        cout << "Please enter object " << i + 1 << "/" << anzahl << ": ";
        cin >> s;
        auto it = converters.end();
        stringstream ss(s);
        char c;
        while (ss.good() && ss.rdbuf()->in_avail())
        {
            do
            {
                c = ss.peek();
                it = converters.find(c);
            } while (ss.good() && ss.rdbuf()->in_avail() && it == converters.end());
            objects[i] = it->second(ss);
        }
    }

    // Objekte ausgeben
    for (int i = 0; i < anzahl; i++)
    {
        cout << "Object Nb. " << i + 1 << ": ";
        objects[i]->Print(true);
    }

    return 0;
}
