#ifndef MANAGER_HH_
#define MANAGER_HH_

#include "employee.hh"

class Boss : public Angestellte
{
    double bossGehalt;

public:
    Boss(const char *, const char *, double = 0.0);
    void setBossGehalt(double);
    virtual double einkommen() const;
    virtual void print() const;
};

#endif
