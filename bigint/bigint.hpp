// Header file for project 1 - Bigint
// Livia Coduto
// CS23001

#include <iostream>

#ifndef BIGINT_PROJECT
#define BIGINT_PROJECT
const int CAPACITY = 200;

class bigint {
    public:
        bigint(); //initializes bigint to 0
        bigint(int userInput); //initializes array to int
        bigint(const char arr[]); //initializes array to char

        void debugPrint(std::ostream&) const;

        bool operator== (const bigint& numbers) const;
        bigint operator+ (const bigint&) const;
        int operator[](int i) const;
        bigint operator* (const bigint b) const;

        bigint timesDigit(int) const;
        bigint times10(int) const;

        friend std::ostream& operator<< (std::ostream& out, const bigint& b);
        friend std::istream& operator>> (std::istream& in, bigint& b);

    private:
        int bigIntArr[CAPACITY];
};

#endif