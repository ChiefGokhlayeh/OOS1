#include "date.hh"

#include <iostream>
#include <sstream>

using namespace std;

#define DAYS_PER_MONTH(m) (31)
#define MONGTHS_PER_YEAR (12)

Datum::Datum(int tag, int monat, int jahr)
    : tag(tag), monat(monat), jahr(jahr)
{
}

Datum::Datum(const string &str)
    : Datum(str.c_str())
{
}

Datum::Datum(const char *cstr)
{
    char _;
    stringstream ss(cstr);
    ss >> tag;
    ss >> _;
    ss >> monat;
    ss >> _;
    ss >> jahr;
}

Datum Datum::operator+(int tage)
{
    int d = tag;
    int m = monat;
    int y = jahr;

    for (; tage > 0;)
    {
        int days_to_add = tage;
        bool next_month = false;
        if (d + days_to_add > DAYS_PER_MONTH(m))
        {
            days_to_add = DAYS_PER_MONTH(m);
            next_month = true;
        }
        tage -= days_to_add;
        d += days_to_add % DAYS_PER_MONTH(m);
        if (next_month)
        {
            if (m < MONGTHS_PER_YEAR)
            {
                m++;
            }
            else
            {
                m = 1;
                y++;
            }
        }
    }

    Datum date(d % DAYS_PER_MONTH(monat), m, y);
    return date;
}

ostream &operator<<(ostream &os, const Datum &d)
{
    os << d.tag << "." << d.monat << "." << d.jahr;
}
