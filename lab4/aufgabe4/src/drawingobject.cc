#include "drawingobject.hh"

#include <iostream>

using namespace std;

extern bool debugConstructor;

DrawingObject::DrawingObject()
    : ObjectCounter()
{
    if (debugConstructor)
    {
        cout << "Konstrutor der Klasse DrawingObject, Object: " << GetId() << endl;
    }
}

DrawingObject::~DrawingObject()
{
    if (debugConstructor)
    {
        cout << "Destruktor der Klasse DrawingObject, Object: " << GetId() << endl;
    }
}
