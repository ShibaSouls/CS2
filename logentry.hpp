////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
        Date() : day(), month(), year(0) {};

        void daySet(String linestring) {day = linestring;};
        void monthSet(String linestring) {month = linestring;};
        void yearSet(int linevalue){year = linevalue;};
        String dayGet() const {return day;};
        String monthGet() const {return month;};
        int yearGet() const {return year;};

private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
        Time() {};

        void hourSet(int linevalue) {hour = linevalue;};
        void minSet(int linevalue) {minute = linevalue;};
        void secSet(int linevalue) {second = linevalue;};
        int hourGet() const {return hour;};
        int minGet() const {return minute;};
        int secGet() const {return second;};

  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
    LogEntry() {};

    LogEntry(String);

    String getHost() const {return host;};
    int getBytes() const {return number_of_bytes;};
    int toInt(const String&);

    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);


#endif