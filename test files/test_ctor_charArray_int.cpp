//test

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1(10, "abc");

        assert(s1.capacity() == 10);
		assert(s1 == "abc");
    }
    std::cout << "Done testing char int ctor." << std::endl;
}