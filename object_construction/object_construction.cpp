// implementation for lab 6
// Livia Coduto
// 2/24/2021

#include "object_construction.hpp"

Object::Object(){
    std::cout << "Called default constructor" << std::endl;
}

Object::~Object(){
    std::cout << "Called destructor" << std::endl;
}

Object::Object(const Object& copy){
    std::cout << "Called copy constructor" << std::endl;
}

void Object::operator=(const Object&){
    std::cout << "Called assignment" << std::endl;
}