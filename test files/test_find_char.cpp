// tests find char

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("dog");
        
        int location = s1.findch(0, 'd');

        assert(location == 0);
    }

    {
        String s1("dog");
        
        int location = s1.findch(0, 'o');

        assert(location == 1);
    }

    {
        String s1("dog");
        
        int location = s1.findch(0, 'g');

        assert(location == 2);
    }

    {
        String s1("dog");

        int location = s1.findch(1, 'o');

        assert(location == 1);
    }
    {
        String s1("dog");

        int location = s1.findch(1, 'g');

        assert(location == 2);
    }
    std::cout << "Done testing findch." << std::endl;
}