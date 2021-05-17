// swap test

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("abc");
        String s2("");

		s1.swap(s2);

        assert(s1 == "");
    }

	{
        String s1("");
        String s2("abc");

		s1.swap(s2);
		
        assert(s1 == "abc");
    }

	{
        String s1("");
        String s2("");

		s1.swap(s2);
		
        assert(s1 == "");
    }

	{
        String s1("abc");
        String s2("abc");

		s1.swap(s2);
		
        assert(s1 == "abc");
    }

	{
        String s1("def");
        String s2("abc");

		s1.swap(s2);
		
        assert(s1 == "abc");
    }
    std::cout << "Done testing swap assign." << std::endl;
}