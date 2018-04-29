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
    int ans;
    o >> ans;
    ci.hour = ci.range(ans);
    return o;
}
//Equals operator
CircularInt& CircularInt::operator=(int a){
  hour = range(a);
  return *this;
}
//or operator
CircularInt CircularInt::operator|(int a){
  CircularInt tmp(min,max);
  int ans = hour|a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator|(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour|other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator|(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a|ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
}
//And operator
CircularInt CircularInt::operator&(int a){
  CircularInt tmp(min,max);
  int ans = hour&a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator&(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour&other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator&(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a&ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
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
// CircularInt  CircularInt::operator/(int x){
// 	CircularInt tmp = *this;
// 	for(int i=min;i<=max;i++){
// 		if(min*x==hour){
// 			tmp.hour=i;
// 			return tmp;
// 		}
// 		min+=1;
// 	}
// 	throw std::invalid_argument( "There is no such a number\n" );
// }
// //
CircularInt CircularInt::operator/(int a){
  CircularInt tmp(min,max);
  if( hour%a == 0 ){
    int ans = hour/a;
    tmp.hour = range(ans);
    return tmp;
  }
  throw std::invalid_argument( "There is no such a number\n" );
}
CircularInt CircularInt::operator/(const CircularInt other){
  CircularInt tmp(min,max);
  if( hour%other.hour == 0 ){
    int ans = hour/other.hour;
    tmp.hour = range(ans);
    return tmp;
  }
  throw std::invalid_argument( "There is no such a number\n" );
}
CircularInt operator/(int a, const CircularInt& ci){
  CircularInt tmp = ci;
  if( a%ci.hour == 0 ){
    int ans = a/ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
  }
  throw std::invalid_argument( "There is no such a number\n" );
}
//Multiplication operator
CircularInt CircularInt::operator*(int a){
  throw("multiplication 1\n");
}
CircularInt CircularInt::operator*(const CircularInt other){
  throw("multiplication 2\n");
}
CircularInt operator*(int a, const CircularInt& ci){
  throw("multiplication 3\n");
}
//Xor operator
CircularInt CircularInt::operator^(int a){
  CircularInt tmp(min,max);
  int ans = hour^a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator^(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour^other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator^(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a^ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
}
//Modulus operator
CircularInt CircularInt::operator%(int a){
  CircularInt tmp(min,max);
  int ans = hour%a;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt CircularInt::operator%(const CircularInt other){
  CircularInt tmp(min,max);
  int ans = hour%other.hour;
  tmp.hour = range(ans);
  return tmp;
}
CircularInt operator%(int a, const CircularInt& ci){
  CircularInt tmp = ci;
    int ans = a%ci.hour;
    tmp.hour = tmp.range(ans);
    return tmp;
}
//Unary operator
CircularInt& CircularInt::operator/=(int a){
  if(hour%a == 0){
    int ans = hour/a;
    hour = range(ans);
    return *this;
  }
  throw std::invalid_argument( "There is no such a number\n" );
}
CircularInt& CircularInt::operator&=(int a){
  int ans = hour&a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator|=(int a){
  int ans = hour|a;
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
CircularInt& CircularInt::operator^=(int a){
  int ans = hour^a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator%=(int a){
  int ans = hour%a;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator/=(const CircularInt& other){
  if(hour%other.hour == 0){
    int ans = hour/other.hour;
    hour = range(ans);
    return *this;
  }
  throw std::invalid_argument( "There is no such a number\n" );
}
CircularInt& CircularInt::operator&=(const CircularInt& other){
  int ans = hour&other.hour;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator|=(const CircularInt& other){
  int ans = hour|other.hour;
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
CircularInt& CircularInt::operator^=(const CircularInt& other){
  int ans = hour^other.hour;
  hour = range(ans);
  return *this;
}
CircularInt& CircularInt::operator%=(const CircularInt& other){
  int ans = hour%other.hour;
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
