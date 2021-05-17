// tests equal

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("abc");
        String s2("abc");

        assert(s1 == s2);
    }

    {
        String s1('a');
        String s2('a');

        assert(s1 == s2);
    }

    { 
        String s1('a');

        assert(s1 == 'a');
    }

    {
        String s1("ab");

        assert(s1 == "ab");
    }

    {
        String s1("abc");

        assert(s1 == "abc");
    }

    {
        String s1("abc");

        assert(s1 != "abcd");
    }
	
    {
        String s1("1234567890");

        assert(s1 == "1234567890");

        s1 = String("12345");
        assert(s1 == "12345");
    }
    std::cout << "Done testing == operator." << std::endl;
}