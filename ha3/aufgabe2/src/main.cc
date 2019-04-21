#include "customer.hh"

#include <iostream>
#include <time.h>
#include <array>

using namespace std;

int main()
{
    srand(time(nullptr));

    constexpr auto customerCount = 10;
    array<Customer, customerCount> customers;

    cout << "Number of customers: " << Customer::GetCount() << endl;

    cout << "Performing transactions..." << endl;
    for (auto &c : customers)
    {
        for (unsigned int i = 0; i < (unsigned int) max(rand() % 20, 1); i++)
        {
            c.Buy((rand() % 10000) * 0.01);
        }
        c.Print();
    }
    cout << "Number of customers: " << Customer::GetCount() << endl;

    {
        /* In lower scope to enforce destruction upon exit. */
        cout << "Copying customers..." << endl;
        array<Customer, customerCount> copyOfCustomers = customers;
    }
    cout << "Number of customers: " << Customer::GetCount() << endl;

    return 0;
}
