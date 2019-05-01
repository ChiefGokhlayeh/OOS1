#include "polygon3.hh"

#include <iostream>
#include <sstream>

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
    cout << ToString();
    if (lf)
        cout << endl;
}

string PolygonPoint::ToString() const
{
    stringstream buf;
    const PolygonPoint *next = this;
    do
    {
        buf << next->point.ToString();
        next = next->GetNext();
        if (next != nullptr)
            buf << " - ";
    } while (next != nullptr);

    return buf.str();
}

Polygon::Polygon()
    : root(nullptr)
{
}

Polygon::Polygon(const Point &p)
    : root(new PolygonPoint(p))
{
}

Polygon::Polygon(const char *c)
{
    stringstream buf(c);
    buf >> *this;
}

Polygon::Polygon(const string &str)
{
    stringstream buf(str);
    buf >> *this;
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
    cout << ToString();
    if (lf)
        cout << endl;
}

string Polygon::ToString() const
{
    stringstream buf;
    buf << "|";
    if (root != nullptr)
        buf << root->ToString();
    buf << "|";
    return buf.str();
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
    /* Do to owner-ship issues over who owns a PolygonPoint it is better to copy
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

istream &operator>>(istream &is, Polygon &poly)
{
    bool started = false;
    PolygonPoint *cur = nullptr;
    while (!is.eof())
    {
        switch (is.get())
        {
            case '|':
                if (!started)
                {
                    Point point;
                    is >> point;
                    poly.root = new PolygonPoint(point);
                    cur = poly.root;
                }
                started = true;
                break;
            case '-':
                if (started)
                {
                    Point point;
                    is >> point;
                    cur->SetNext(new PolygonPoint(point));
                    cur = cur->GetNext();
                }
                break;
            default:
                /* ignore */
                break;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, Polygon &poly)
{
    os << poly.ToString();
    return os;
}
