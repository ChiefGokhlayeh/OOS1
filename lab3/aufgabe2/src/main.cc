#include "mystring2.hh"
#include <iostream>

using namespace std;

int main()
{
    /* Oops, this already works because mystring2 (and mystring) are already
     * const-correct. */
    const MyString cs("Ein konstanter String");
    MyString s(cs);
    s.Assign(cs);
    s.Append(cs);
    cout << cs.C_str() << endl;
    cout << cs.Size() << endl;
    cout << cs.Capacity() << endl;
    cout << boolalpha << cs.Empty() << endl;
    s = cs + cs;
    cout << (cs == cs) << endl;
    s = cs;
    cout << cs << endl;
    s.At(1) = 'X';
    s[2] = 'Y';
    cout << s << endl;
    return 0;
}
