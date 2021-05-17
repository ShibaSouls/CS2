// main function for lab 6
// Livia Coduto
// 2/24/2021

#include "object_construction.hpp"
#include "object_construction.cpp"
#include <iostream>

void testCopyCtor(Object test){
}

int main() {

    Object one;
    Object two;

    one = two;
    two = one;

    Object three(one);

    three.~Object();

    return 0;
}