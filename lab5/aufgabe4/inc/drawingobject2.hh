#ifndef DRAWINGOBJECT_HH_
#define DRAWINGOBJECT_HH_

#include "objectcounter.hh"

class DrawingObject : public ObjectCounter
{
public:
    DrawingObject();
    virtual ~DrawingObject();

    virtual void Print(bool lf = false) const = 0;
};

#endif
