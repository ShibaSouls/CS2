////////////////////////////////////////////////////////////
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        3/17/2021
// Author:      Livia Coduto 
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
   std::vector<String> vec = s.split(' ');

   if(vec.size() == 10) {
     host = vec[0];
		
		 std::vector<String> dateTime = vec[3].split(':');
		 std::vector<String> dateString = dateTime[0].split('/');
		
		 String newDay = dateString[0].substr(1, dateString[0].length() - 1);
		
		 date.daySet(newDay);
     date.monthSet(dateString[1]);
     date.yearSet(dateString[2].toInt());
        
     time.hourSet(dateTime[1].toInt());
     time.minSet(dateTime[2].toInt());
     time.secSet(dateTime[3].toInt());
		
		 request = vec[5] + vec[6] + " " + vec[7];
		 status = vec[8];
		
		if (vec[9] == '-') {
      number_of_bytes = 0;
    }
		else {
      number_of_bytes = vec[9].toInt();
		}
  }
   else {
     host = "";

     date.daySet("");
     date.monthSet("");
     date.yearSet(0);

     time.hourSet(0);
     time.minSet(0);
     time.secSet(0);

     request = "";
     status = "";
     number_of_bytes = 0; 
  }	
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
  std::vector<LogEntry> result;

  String tmp;
  char ch;

  while(in.get(ch)) {
    tmp = tmp + ch;

    if(ch == '\n') {
	    result.push_back(tmp);
	    tmp[0] = 0;
    }
  }
  return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &log) {

  for(unsigned int i=0; i < log.size(); ++i) {
	  out << log.at(i) << std::endl;
  } 
}


////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& log) {

  for(unsigned int i = 0; i < log.size(); ++i) {
	  out << log.at(i).getHost() << std::endl;
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &log) {

	int byteTotal = 0;

	for(unsigned int i=0; i < log.size(); ++i) {
		byteTotal += log.at(i).getBytes();
	}
  return byteTotal;
}


std::ostream& operator<<(std::ostream& out, const LogEntry& log){
  out << "Host: " << log.host << std::endl;
  
  out << "Date: " << log.date.dayGet() << "/" << log.date.monthGet() << "/" << log.date.yearGet() << std::endl;
	out << "Time: " << log.time.hourGet() << ":" << log.time.minGet() << ":" << log.time.secGet() << std::endl;
  
	out << "Request: " << log.request << std::endl;
	out << "Status: " << log.status << std::endl;
	out << "Bytes: " << log.number_of_bytes << std::endl;

  return out;
}

int LogEntry::toInt(const String& s){
  int sum = 0;
  for(int i = 0; i < s.length(); ++i) {
    sum *= 10;
    sum += (s[i]-'0');
  }
  return sum;
}
