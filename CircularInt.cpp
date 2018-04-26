#include "CircularInt.hpp"

CircularInt::CircularInt(int low, int high){
  hour = low;
  min=low;
  max=high;
  modulo = max-min+1;
}
CircularInt::CircularInt(const CircularInt& other){
  min = other.min;
  max=other.max;
  hour=other.hour;
  modulo=other.modulo;
}
CircularInt::~CircularInt(){};

//Plus operator
CircularInt CircularInt::operator+(int a){
  CircularInt tmp(min,max);
  int ans = hour+a;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt CircularInt::operator+(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour+other.hour;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt operator+(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a+ci.hour;
    tmp.hour = (ans%tmp.modulo + tmp.modulo)%tmp.modulo;
    return tmp;
}

//Minus operator
CircularInt CircularInt::operator-(int a){
  CircularInt tmp(min,max);
  int ans = hour-a;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt& CircularInt::operator-(){
  int ans = -hour;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
CircularInt CircularInt::operator-(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour-other.hour;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt operator-(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = a-ci.hour;
  tmp.hour = (ans%tmp.modulo + tmp.modulo)%tmp.modulo;
  return tmp;
}

//Division operator
CircularInt CircularInt::operator/(int a){
  CircularInt tmp(min,max);
  int ans = hour/a;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt CircularInt::operator/(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour/other.hour;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt operator/(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = a/ci.hour;
  tmp.hour = (ans%tmp.modulo + tmp.modulo)%tmp.modulo;
  return tmp;
}

//Multiply operator
CircularInt CircularInt::operator*(int a){
  CircularInt tmp(min,max);
  int ans = hour*a;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt CircularInt::operator*(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour*other.hour;
  tmp.hour = (ans%modulo + modulo)%modulo;
  return tmp;
}
CircularInt operator*(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = ci.hour*a;
  tmp.hour = (ans%tmp.modulo + tmp.modulo)%tmp.modulo;
  return tmp;
}
CircularInt& CircularInt::operator*=(int a){
  int ans = hour*a;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
CircularInt& CircularInt::operator+=(int a){
  int ans = hour+a;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}

CircularInt& CircularInt::operator-=(int a){
  int ans = hour-a;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
CircularInt& CircularInt::operator++(){
  int ans = hour + 1;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
const CircularInt CircularInt::operator++(int){
    CircularInt cpy(*this);
    int ans = hour + 1;
    hour = (ans%modulo + modulo)%modulo;
    return cpy;
}
const CircularInt CircularInt::operator--(int){
  int ans = hour-1;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
CircularInt& CircularInt::operator--(){
  int ans = hour - 1;
  hour = (ans%modulo + modulo)%modulo;
  return *this;
}
//
std::ostream& operator<< (std::ostream& o, CircularInt const& ci)
{
  return o << ci.hour;
}
