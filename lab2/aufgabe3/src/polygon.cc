#include "polygon.hh"

#include <iostream>

using namespace std;

PolygonPoint::PolygonPoint(const Point &p, PolygonPoint *next)
    : point(p),
      next(next)
{
}

PolygonPoint::PolygonPoint(const PolygonPoint &orig)
    : point(orig.point)
{
    if (orig.HasNext())
    {
        next = new PolygonPoint(*orig.next);
    }
}

PolygonPoint::~PolygonPoint()
{
    if (next != nullptr)
    {
        delete next;
        next = nullptr;
    }
}

const Point &PolygonPoint::GetPoint() const
{
    return point;
}

PolygonPoint *PolygonPoint::GetNext() const
{
    return next;
}

void PolygonPoint::SetNext(PolygonPoint *next)
{
    this->next = next;
}

bool PolygonPoint::HasNext() const
{
    return next != nullptr;
}

void PolygonPoint::Move(double dx, double dy)
{
    PolygonPoint *next = this;
    do
    {
        next->point.Move(dx, dy);
        next = next->GetNext();
    } while (next != nullptr);
}

void PolygonPoint::Print(bool lf) const
{
    const PolygonPoint *next = this;
    do
    {
        next->point.Print(false);
        next = next->GetNext();
        if (next != nullptr)
            cout << " - ";
    } while (next != nullptr);

    if (lf)
        cout << endl;
}

Polygon::Polygon()
    : root(nullptr)
{
}

Polygon::Polygon(const Point &p)
    : root(new PolygonPoint(p))
{
}

Polygon::~Polygon()
{
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }
}

void Polygon::Move(double dx, double dy)
{
    if (root != nullptr)
        root->Move(dx, dy);
}

void Polygon::Print(bool lf) const
{
    cout << "|";
    if (root != nullptr)
        root->Print(false);
    cout << "|";
    if (lf)
        cout << endl;
}

Polygon &Polygon::AddPoint(Point &point)
{
    if (root == nullptr)
    {
        root = new PolygonPoint(point);
    }
    else
    {
        PolygonPoint *p = root;
        while (p->HasNext())
            p = p->GetNext();

        p->SetNext(new PolygonPoint(point));
    }

    return *this;
}

Polygon &Polygon::Append(const Polygon &polygon)
{
    /* Due to ownership issues over who owns a PolygonPoint it is better to copy
     * every element from the other polygon before appending. */
    if (root == nullptr)
    {
        root = new PolygonPoint(*polygon.root);
    }
    else
    {
        PolygonPoint *p = root;
        while (p->HasNext())
            p = p->GetNext();

        p->SetNext(new PolygonPoint(*polygon.root));
    }

    return *this;
}
