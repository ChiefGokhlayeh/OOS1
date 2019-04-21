#include "ObjectCounter.hh"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    srand(time(nullptr));
    size_t objCount = max(rand() % 20, 2);
    vector<ObjectCounter *> objs;
    cout << "Allocating " << objCount << " object(s)..." << endl;
    for (size_t i = 0; i < objCount; i++)
    {
        ObjectCounter *o = new ObjectCounter();
        objs.push_back(o);
        cout << "Id: " << o->GetId() << endl;
    }
    cout << "Max Id: " << ObjectCounter::GetMaxId() << endl;
    cout << "Number of objects: " << ObjectCounter::GetNumberOfObjects() << endl;

    size_t deleteCount = max(int(objs.size()) - int(rand() % objs.size()) - 1, 1);
    cout << "Deallocating " << deleteCount << " object(s)..." << endl;
    for (size_t i = 0; i < deleteCount; i++)
    {
        size_t indexToDelete = rand() % objs.size();
        const ObjectCounter *o = objs[indexToDelete];
        cout << "Deleting " << o->GetId() << " at index " << indexToDelete << endl;
        objs.erase(objs.begin() + indexToDelete);
        delete o;
    }

    cout << "Number of objects: " << ObjectCounter::GetNumberOfObjects() << endl;

    for (const auto &o : objs)
    {
        cout << "Id: " << o->GetId() << endl;
    }

    return 0;
}
