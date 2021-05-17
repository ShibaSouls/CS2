//tests char array

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
        String s1("6234567890");

        assert(s1 == "6234567890");
        std::cout << "6234567890 == ";
        std::cout << s1;
        std::cout << std::endl;

        s1 = String("62345");
        assert(s1 == "62345");
        std::cout << "62345 == ";
        std::cout << s1;
        std::cout << std::endl;


    }

    std::cout << "Done testing char[] Ctor" << std::endl;
}