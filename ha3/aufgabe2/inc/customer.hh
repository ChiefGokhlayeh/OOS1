#ifndef CUSTOMER_HH_
#define CUSTOMER_HH_

class Customer
{
  private:
    static unsigned int count;
    
    char *name;
    char *address;
    unsigned int age;
    double totalVolume;
    unsigned int transactionCount;
    unsigned int id;

    bool phantom;
  public:
    static unsigned int GetCount();

    Customer(const char* name = "NO NAME", const char* address = "NO ADDRESS", unsigned int age = 0);
    Customer(const Customer &orig);
    ~Customer();

    const char* GetName() const;
    const char* GetAddress() const;
    unsigned int GetAge() const;
    double GetTotalVolume() const;
    unsigned int GetTransactionCount() const;
    unsigned int GetId() const;


    void Buy(double volume);

    void Print() const;
};

#endif
