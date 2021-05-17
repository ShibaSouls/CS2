// test

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1(10);

        assert(s1.capacity() == 10);
    }

	{
        String s1(1);

        assert(s1.capacity() == 1);
    }
    
	{
        String s1(0);

        assert(s1.capacity() == 0);
    }

    std::cout << "Done testing ctor(int)." << std::endl;
}