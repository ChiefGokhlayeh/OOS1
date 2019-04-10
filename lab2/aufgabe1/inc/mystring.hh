#ifndef MYSTRING_HH_
#define MYSTRING_HH_

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

  const char *C_str();

  unsigned int Size() const;
  unsigned int Capacity() const;
  bool Empty() const;
  char &At(unsigned int i);

  void Clear();
};

#endif
