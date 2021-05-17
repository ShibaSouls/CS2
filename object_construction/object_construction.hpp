// header for lab 6
// Livia Coduto
// 2/24/2021

#include <iostream>

#ifndef Object_Construction
#define Object_Construction

class Object {
public:
    Object(); //default
    ~Object(); //destructor
    Object(const Object&); //copy
    void operator=(const Object&); //assignment
private:

};

#endif