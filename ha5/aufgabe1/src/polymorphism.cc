#include <iostream>
using namespace std;

class A
{
public:
    virtual void f()
    {
        cout << "A::f() - ";
        g();
    }
    virtual void g()
    {
        cout << "A::g()" << endl;
    }
    virtual void h(int)
    {
        cout << "A::h(int)" << endl;
    }
};

class B : public A
{
public:
    virtual void h(char)
    {
        cout << "B::h(char)" << endl;
    }
};

class C : public B
{
public:
    virtual void f()
    {
        cout << "C::f() - ";
        A::f();
    }
    virtual void g()
    {
        cout << "C::g()" << endl;
    }
    virtual void h(int)
    {
        cout << "C::h(int)" << endl;
    }
    virtual void h(char)
    {
        cout << "C::h(char)" << endl;
    }
};

int main()
{
    C c;
    A *aptr = &c;
    B &bref = c;

    cout << " 1. ";
    c.f();
    cout << " 2. ";
    c.A::f();
    cout << " 3. ";
    aptr->f();
    cout << " 4. ";
    (*aptr).f();
    cout << " 5. ";
    ((A)(*aptr)).f();
    cout << " 6. ";
    bref.f();
    cout << " 7. ";
    dynamic_cast<B *>(aptr)->f();
    cout << " 8. ";
    B(bref).f();
    cout << " 9. ";
    bref.h(1);
    cout << "10. ";
    c.h('a');
    cout << "11. ";
    aptr->h('a');
    cout << "12. ";
    bref.h('a');

    return 0;
}
