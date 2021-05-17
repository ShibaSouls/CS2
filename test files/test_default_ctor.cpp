// test program project 2
// Livia Coduto
// tests default ctor

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1;
        String s2;

        assert(s1 == s2);
    }
    std::cout << "Done testing default String Ctor." << std::endl;
}