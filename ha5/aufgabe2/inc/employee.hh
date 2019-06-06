#ifndef EMPLOYEE_HH_
#define EMPLOYEE_HH_

class Angestellte
{
    char *vorname;
    char *nachname;

public:
    Angestellte(const char *, const char *);
    ~Angestellte();
    const char *getVorname() const;
    const char *getNachname() const;
    virtual double einkommen() const = 0;
    virtual void print() const;
};

#endif
