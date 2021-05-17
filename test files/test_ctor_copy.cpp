//tests copy

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("abc");
        String s2(s1);

        assert(s1 == s2);
    }

	{
        String s1('a');
        String s2(s1);

        assert(s1 == s2);
    }

    {
        String s1("");
		String s2(s1);

        assert(s1 == s2);
    }

    {
        String s1("abc");
		String s2(s1);

        assert(s1 == s2);
    }

    {
        String s1("6234567890");

        assert(s1 == "6234567890");

        s1 = String("62345");
		String s2(s1);

        assert(s1 == s2);

    }

    std::cout << "Done testing copy String Ctor." << std::endl;
}