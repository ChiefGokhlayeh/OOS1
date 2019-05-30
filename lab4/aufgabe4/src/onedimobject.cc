#include "onedimobject.hh"

#include <iostream>

using namespace std;

extern bool debugConstructor;

OneDimObject::OneDimObject()
    : DrawingObject()
{
    if (debugConstructor)
    {
        cout << "Konstrutor der Klasse OneDimObject, Object: " << GetId() << endl;
    }
}

OneDimObject::~OneDimObject()
{
    if (debugConstructor)
    {
        cout << "Destruktor der Klasse OneDimObject, Object: " << GetId() << endl;
    }
}
