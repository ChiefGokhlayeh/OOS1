#ifndef WORKER_HH_
#define WORKER_HH_

#include "employee.hh"

class Arbeiter : public Angestellte
{
    double stundenLohn;
    double stunden;

public:
    Arbeiter(const char *, const char *, double = 0.0, double = 0.0);
    void setStundenLohn(double);
    void setStunden(double);
    virtual double einkommen() const;
    virtual void print() const;
};

#endif
