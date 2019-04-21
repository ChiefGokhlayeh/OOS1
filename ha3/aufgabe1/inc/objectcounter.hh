#ifndef OBJECTCOUNTER_HH_
#define OBJECTCOUNTER_HH_

class ObjectCounter
{
  private:
    static unsigned int maxId;
    static unsigned int number;

    const unsigned int id;
  public:
    static unsigned int GetMaxId();
    static unsigned int GetNumberOfObjects();

    unsigned int GetId() const;

    ObjectCounter();
    ~ObjectCounter();
};

#endif
