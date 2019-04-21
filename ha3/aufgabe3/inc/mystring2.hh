#ifndef MYSTRING_HH_
#define MYSTRING_HH_

#include <ostream>

class MyString
{
private:
  char *strPtr;
  unsigned int strSize;
  unsigned int strCapacity;
  char nullChar;

public:
  MyString();
  MyString(const char *cstr);
  MyString(const MyString &mystr);
  ~MyString();

  void Reserve(unsigned int c);
  MyString &Append(const MyString &mystr);
  MyString &Assign(const MyString &mystr);

  const char *C_str() const;

  unsigned int Size() const;
  unsigned int Capacity() const;
  bool Empty() const;
  char &At(unsigned int i);

  void Clear();

  friend MyString operator+(const MyString &left, const MyString &right);
  MyString &operator+=(const MyString &other);
  MyString &operator=(const MyString &other);
  bool operator==(const MyString &other) const;
  char &operator[](unsigned int i);
  friend std::ostream &operator<<(std::ostream &os, const MyString& myStr);
};

#endif
