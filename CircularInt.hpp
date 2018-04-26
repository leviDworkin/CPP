#pragma once
#include <iostream>
using namespace std;

class CircularInt{
private:
  int min,max;
  int hour , modulo;
public:
  //Constructor and Destructor
  CircularInt(int low, int high);
  CircularInt(const CircularInt& other);
  ~CircularInt();

  //Methods
  int range(int a);
  friend std::ostream& operator<< (std::ostream& o, CircularInt const& ci);
  friend std::istream& operator>> (std::istream& o, CircularInt& ci);

  CircularInt& operator=(int a);

  CircularInt operator+(int a);
  CircularInt operator+(const CircularInt other);
  friend CircularInt operator+(int a, const CircularInt& ci);

  CircularInt operator-(int a);
  CircularInt operator-();
  CircularInt operator-(const CircularInt other);
  friend CircularInt operator-(int a, const CircularInt& ci);

  CircularInt operator/(int a);
  CircularInt operator/(const CircularInt other);
  friend CircularInt operator/(int a, const CircularInt& ci);


  CircularInt operator*(int a);
  CircularInt operator*(const CircularInt other);
  friend CircularInt operator*(int a, const CircularInt& ci);

  CircularInt operator^(int a);
  CircularInt operator^(const CircularInt other);
  friend CircularInt operator^(int a, const CircularInt& ci);

  CircularInt operator%(int a);
  CircularInt operator%(const CircularInt other);
  friend CircularInt operator%(int a, const CircularInt& ci);

  CircularInt& operator/=(int a);
  CircularInt& operator*=(int a);
  CircularInt& operator+=(int a);
  CircularInt& operator-=(int a);
  CircularInt& operator^=(int a);
  CircularInt& operator%=(int a);

  CircularInt& operator/=(const CircularInt& other);
  CircularInt& operator*=(const CircularInt& other);
  CircularInt& operator+=(const CircularInt& other);
  CircularInt& operator-=(const CircularInt& other);
  CircularInt& operator^=(const CircularInt& other);
  CircularInt& operator%=(const CircularInt& other);

  CircularInt& operator++(); //prefix
  const CircularInt operator++(int); //postfix
  const CircularInt operator--(int);
  CircularInt& operator--();

  bool operator==(int a);
  bool operator==(const CircularInt& other);
  friend bool operator==(int a, const CircularInt& ci);
  bool operator!=(int a);
  bool operator!=(const CircularInt& other);
  friend bool operator!=(int a, const CircularInt& ci);

  bool operator<(int a);
  bool operator<(const CircularInt& other);
  friend bool operator<(int a, const CircularInt& ci);

  bool operator>(int a);
  bool operator>(const CircularInt& other);
  friend bool operator>(int a, const CircularInt& ci);

  bool operator<=(int a);
  bool operator<=(const CircularInt& other);
  friend bool operator<=(int a, const CircularInt& ci);

  bool operator>=(int a);
  bool operator>=(const CircularInt& other);
  friend bool operator>=(int a, const CircularInt& ci);
};
