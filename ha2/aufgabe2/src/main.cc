#include "mystring.hh"

#include <iostream>

using namespace std;

int main()
{
    MyString s1;
    MyString s2("Hochschule Esslingen");
    cout << s1.C_str() << endl;
    cout << s2.C_str() << endl;
    s1.Assign(s2);
    s2.Assign(MyString(" - University of Applied Sciences"));
    s1.Append(s2);
    cout << s1.C_str() << endl;
    cout << s2.C_str() << endl;
    MyString s3(s1);
    s1.At(21) = 'X';
    s1.At(2000) = 'O';
    cout << s1.C_str() << endl;
    cout << s2.C_str() << endl;
    if (!s3.Empty())
    {
        cout << "Laenge von s3:     " << s3.Size() << endl;
        cout << "Kapazitaet von s3: " << s3.Capacity() << endl;
        cout << s3.C_str() << endl;
    }
    s3.Clear();
    cout << "Laenge von s3:     " << s3.Size() << endl;
    cout << "Kapazitaet von s3: " << s3.Capacity() << endl;
    cout << s3.C_str() << endl;
    return 0;
}
