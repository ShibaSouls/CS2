// tests char ctor

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1('a');
        String s2('a');

        assert(s1 == s2);
    }
    std::cout << "Done testing default char Ctor." << std::endl;
}