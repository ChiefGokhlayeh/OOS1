#include "fifo.hh"

#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    Fifo<char> f1(10);
    while (f1.Push('a' + i) > -1)
    {
        cout << "Push " << char('a' + i) << " (" << i+1 << ")" << endl;
        i++;
    }
    char c = '0';
    while (f1.Pop(&c) > -1)
    {
        cout << "Pop " << c << endl;
    }
    cout << "ReadPos: " << f1.GetReadPos() << endl;
    cout << "WritePos: " << f1.GetWritePos() << endl;
    return 0;
}