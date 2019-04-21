#include "customer.hh"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

unsigned int Customer::count;

unsigned int Customer::GetCount()
{
    return Customer::count;
}

Customer::Customer(const char *name, const char *address, unsigned int age)
    : name(new char[strlen(name)]), address(new char[strlen(address)]),
      age(age), totalVolume(0), transactionCount(0), id(Customer::count + 1),
      phantom(false)
{
    strcpy(this->name, name);
    strcpy(this->address, address);

    Customer::count++;
}

Customer::Customer(const Customer &orig)
    : name(new char[strlen(orig.name)]), address(new char[strlen(orig.address)]),
      age(orig.age), totalVolume(orig.totalVolume), transactionCount(orig.transactionCount),
      id(orig.id), phantom(true)
{
    strcpy(this->name, name);
    strcpy(this->address, address);
}

Customer::~Customer()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
    if (address != nullptr)
    {
        delete[] address;
        address = nullptr;
    }

    /* This dtor normally has no way of differentiating between "normal" and
     * copied object. While the deletion of a "normal" object should decrement
     * total customer count, a copied object does not increment that counter
     * and therefore should not.
     * The "phantom" flag is a workaround for this generally broken idea of
     * maintaining a customer count value via ctor and dtor. Perhaps a better
     * solution would involve a customer factory or not maintaining the customer
     * count as an attribute of this class, but rather some database-layer
     * higher up.
     */
    if (!phantom)
        Customer::count--;
}

const char *Customer::GetName() const
{
    return name;
}

const char *Customer::GetAddress() const
{
    return address;
}

unsigned int Customer::GetAge() const
{
    return age;
}

double Customer::GetTotalVolume() const
{
    return totalVolume;
}

unsigned int Customer::GetTransactionCount() const
{
    return transactionCount;
}

unsigned int Customer::GetId() const
{
    return id;
}

void Customer::Buy(double volume)
{
    totalVolume += volume;
    transactionCount++;
}

void Customer::Print() const
{
    cout << "Kunde " << name << " aus " << address << " (ID = " << id << ", "
         << age << " Jahre) hatte " << transactionCount
         << " Transaktion(en) und " << fixed << setprecision(2) << totalVolume << " Euro Umsatz." << endl;
}
