// implementation of methods for project 2, milestone 3
// Livia Coduto
// 2/24/2021

#include "string.hpp"
#include <vector>

int String::toInt()
{
	int start = length() - 1;

	if (str[start] == '-')
		return 0;
	
	int newInt = 0;
	int carry = 1;

	for (int i = start; i >= 0; --i)
	{
		newInt += (int(str[i] - int('0')) * carry);
		carry *= 10;
	}

	return newInt;
	
}


//split
std::vector<String> String::split(char ch)const{
  std::vector<String> result;
  String s1;

  for(int i = 0; str[i] != 0; ++i){

    if(str[i] != ch) {
      s1 = s1 + str[i];
    }
    else {
      result.push_back(s1);

      if(str[i+1]!=ch) {
        s1 = str[++i];
      }
      else {
        s1="";
        result.push_back(s1);
        i++;
      }
    }
  }
  result.push_back(s1);
  return result;
}

//String(10) - capacity 10, empty string
String::String(int n){
  stringSize = n + 1;
  str = new char[stringSize];
  str[0] = '\0';
}

//String(10, "abc") - capacity 10 with "abc"
String::String(int n, const char carr[]) : String(n){
  int carr_leng = 0;
  while(carr[carr_leng] != '\0')
    ++carr_leng;
  for(int i = 0; i <= carr_leng; ++i)
    str[i] = carr[i];
  
}

//Resets capacity to N, keeps string intact
void String::resetCapacity(int n) {
  char *temp = new char[n];
  for (int i = 0; i < length(); ++i)
      temp[i] = str[i];
  delete[] str;
  str = temp;
  stringSize = n;
}

//constructors for (), (char), and (const char[])
String::String(){
  stringSize = 1;
  str = new char[stringSize];
  str[0] = '\0';
}

String::String (char ch) {
  stringSize = 2;
  str = new char[2];
  str[0] = ch;

  if (ch == 0) {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = ch;
  }
  str[1] = '\0';
}  

String::String(const char ch[]){
  int len = 0;
  while(ch[len] != '\0'){
    len++;
  }
  stringSize = len + 1;
  str = new char[stringSize];
  for(int i = 0; i < len; ++i){
    str[i] = ch[i];
  }
  str[len] = '\0';
}

//copy constructor
String::String(const String& rhs)
{
	stringSize = rhs.stringSize;
	str = new char[stringSize];

	for(auto i = 0; i < stringSize; ++i)
	{
		str[i] = rhs.str[i];
	}
}

//destructor
String::~String()
{
	delete[] str;
}

//constant time swap
void String::swap(String& rhs) {
	char* temp = str;
	str = rhs.str;
	rhs.str = temp;

	const auto size = stringSize;
	stringSize = rhs.stringSize;
	rhs.stringSize = size;
}

//assignment copy
String& String::operator=(String rhs)
{
	if (str != nullptr)
		delete[] str;

	str = nullptr;

	stringSize = rhs.stringSize;

	str = new char[stringSize];

	for (auto i = 0; i < stringSize; ++i)
	{
		str[i] = rhs.str[i];
	}

	return *this;
}


//accessor/modifier
char& String::operator[](int i){
  return str[i];
}

//accessor
char String::operator[](int i)const{
  return str[i];
}


// capacity
int String::capacity()const{
  return stringSize -1;
}


// length
int String::length() const
{
	auto length = 0;
	for(auto i = 0; i < stringSize; ++i)
	{
		if(str[i] == '\0')
		{
			length = i;
			return length;
		}
	}
	return length;
}


//concatenation
String String::operator+(const String& rhs)const
{                           
  String result(str);
  if((rhs.length()+length()+1)>capacity())
    result.resetCapacity(rhs.length()+length()+1);
  int offset = length();                       
  int i = 0;
  
  while(rhs.str[i] != '\0'){
    result.str[offset + i] = rhs.str[i];
    ++i;
  }  
  
  result.str[offset + i] = '\0';
  result.stringSize = offset+i+1;
  return result;
}

//concatenation
String& String::operator+=(const String& rhs)
{
	const auto lhsSizeOffset = stringSize - 1;
	const auto rhsSize = rhs.stringSize - 1;
	const auto totalSize = lhsSizeOffset + rhsSize;

	String temp(totalSize + 1);
	
	for (auto i = 0; i < lhsSizeOffset; ++i)
	{
		temp.str[i] = str[i];
	}

	for (auto i = lhsSizeOffset, j = 0; i < totalSize; ++i, ++j)
	{
		temp.str[i] = rhs.str[j];
	}
	temp.str[totalSize] = '\0';

	*this = temp;

	return *this;
}


// bool for operator==
bool String::operator==(const String& rhs) const{
    int i = 0;
    while((str[i] != '\0') && (str[i] == rhs.str[i]))
      ++i;
    return str[i] == rhs.str[i];
}

//bool for operator<
bool String::operator<(const String& rhs)const{
  int i = 0;
  while ((str[i] != '\0') &&
	 (rhs[i] != '\0') && (str[i] == rhs.str[i])){
    ++i;
  }
  return str[i] < rhs.str[i];
}


// I/O overloads
std::istream& operator >> (std::istream& in, String& rhs){
  in >> rhs.str;
  return in;
}

std::ostream& operator << (std::ostream& out, const String& rhs)
{
  for (int i = 0; i < rhs.length(); ++i) {
    out << rhs[i];
  }
    
  return out;
}


// substring
String String::substr(int start, int end) const{
  String result;
  if(start<0)  start=0;
  if(end >= length())  end = length() - 1;
  if (end <0)  return result;
  if (start >= length())  return result;
  if (start > end)  return result;

  int j = 0;
  for (int i=start; i<=end; ++i) {
    result.str[j] = str[i];
    ++j;
  }
  result.str[j] = 0;
  return result;
}


// find char
int String::findch(int pos, char ch)const{
   if((pos > length()) || (pos < 0))
    return -1;
  while((str[pos] != 0) && (str[pos] != ch))
    ++pos;
  if(str[pos] == 0)
    return -1;
  else
    return pos;
}


// find str
int String::findstr(int pos, const String& s) const {
  if (pos < 0) {
    pos = 0;
  }
  if (pos > length() - s.length()) {
    return -1;
  }
  int len = s.length();
  int i = pos;
  while (str[i] != '\0') {
    if (substr(i, i + len - 1) == s) {
      return i;
    }
    ++i;
  }
  return -1;
}


// relational operators
String operator+(const char lhs[], const String& rhs){
  return String(lhs) + rhs;
}

String operator+(char lhs, const String& rhs){
  return String(lhs) + rhs;
}

bool operator==(const char lhs[], const String& rhs){
  return (String(lhs) == rhs);
}
bool operator==(char lhs, const String& rhs){
  return (String(lhs) == rhs);
}

bool operator<(const char lhs[], const String& rhs){
  return (String(lhs) < rhs);
}

bool operator<(char lhs, const String& rhs){
  return (String(lhs) < rhs);
}

bool operator<=(const String& lhs, const String& rhs){
  return !(rhs < lhs);
}

bool operator!=(const String& lhs, const String& rhs){
  return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs){
  return !(lhs < rhs);
}

bool operator>(const String& lhs, const String& rhs){
  return (rhs < lhs);
}