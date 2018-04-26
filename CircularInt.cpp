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

int CircularInt::range(int a){
  int ans = (a%modulo + modulo)%modulo;
  while(ans<min){
    ans+=modulo;
  }
  if(ans==max){return ans%modulo;}
  return ans;
}
//i/o stream operator
std::ostream& operator<< (std::ostream& o, CircularInt const& ci)
{
  return o << ci.hour;
}
std::istream& operator>> (std::istream& o, CircularInt& ci)
{
    o >> ci.hour;
    return o;
}
//Equals operator
CircularInt& CircularInt::operator=(int a){
  hour = (a%modulo + modulo)%modulo;
  return *this;
}
//Plus operator
CircularInt CircularInt::operator+(int a){
  CircularInt tmp(min,max);
  int ans = hour+a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator+(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour+other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator+(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a+ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
}
//Minus operator
CircularInt CircularInt::operator-(int a){
  CircularInt tmp(min,max);
  int ans = hour-a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator-(){
  CircularInt tmp(min,max);
  int ans = -hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator-(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour-other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator-(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = a-ci.hour;
  tmp.hour = tmp.range(ans);
  return tmp;
}
//Division operator
CircularInt CircularInt::operator/(int a){
  CircularInt tmp(min,max);
  int ans = hour/a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator/(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour/other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator/(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = a/ci.hour;
  tmp.hour = tmp.range(ans);
  return tmp;
}
//Multiplication operator
CircularInt CircularInt::operator*(int a){
  CircularInt tmp(min,max);
  int ans = hour*a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator*(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour*other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator*(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  int ans = ci.hour*a;
  tmp.hour = tmp.range(ans);
  return tmp;
}
//Unary operator
CircularInt& CircularInt::operator/=(int a){
  int ans = hour/a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator*=(int a){
  int ans = hour*a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator+=(int a){
  int ans = hour+a;
  hour = range(ans);
  return *this;
}

CircularInt& CircularInt::operator-=(int a){
  int ans = hour-a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator/=(const CircularInt& other){
  int ans = hour/other.hour;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& other){
  int ans = hour*other.hour;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& other){
  int ans = hour+other.hour;
  hour = range(ans);
  return *this;
}

CircularInt& CircularInt::operator-=(const CircularInt& other){
  int ans = hour-other.hour;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator++(){
  int ans = hour + 1;
  hour = range(ans);
  return *this;
}
const CircularInt CircularInt::operator++(int){
    CircularInt cpy(*this);
    int ans = hour + 1;
    hour = range(ans);
    return cpy;
}
const CircularInt CircularInt::operator--(int){
  int ans = hour-1;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator--(){
  int ans = hour - 1;
  hour = range(ans);
  return *this;
}
//Boolean operator
bool CircularInt::operator==(int a){
  if(hour==a){return true;}
  return false;
}
bool CircularInt::operator==(const CircularInt& other){
  if(hour == other.hour){return true;}
    return false;
}
bool operator==(int a, const CircularInt& ci){
  if(a==ci.hour){return true;}
  return false;
}
bool CircularInt::operator!=(int a){
  if(hour!=a){return true;}
  return false;
}
bool CircularInt::operator!=(const CircularInt& other){
  if(hour != other.hour){return true;}
    return false;
}
bool operator!=(int a, const CircularInt& ci){
  if(a!=ci.hour){return true;}
  return false;
}
bool CircularInt::operator<(int a){
  if(hour<a){return true;}
  return false;
}
bool CircularInt::operator<(const CircularInt& other){
  if(hour < other.hour){return true;}
    return false;
}
bool operator<(int a, const CircularInt& ci){
  if(a<ci.hour){return true;}
  return false;
}
bool CircularInt::operator>(int a){
  if(hour>a){return true;}
  return false;
}
bool CircularInt::operator>(const CircularInt& other){
  if(hour > other.hour){return true;}
    return false;
}
bool operator>(int a, const CircularInt& ci){
  if(a>ci.hour){return true;}
  return false;
}
bool CircularInt::operator<=(int a){
  if(hour<=a){return true;}
  return false;
}
bool CircularInt::operator<=(const CircularInt& other){
  if(hour <= other.hour){return true;}
    return false;
}
bool operator<=(int a, const CircularInt& ci){
  if(a<=ci.hour){return true;}
  return false;
}
bool CircularInt::operator>=(int a){
  if(hour>=a){return true;}
  return false;
}
bool CircularInt::operator>=(const CircularInt& other){
  if(hour >= other.hour){return true;}
    return false;
}
bool operator>=(int a, const CircularInt& ci){
  if(a>=ci.hour){return true;}
  return false;
}
