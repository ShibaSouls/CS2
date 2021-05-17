// tests <

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("abc");
        String s2("abcd");

        assert(s1 < s2);
    }

    { 
        String s1("abcde");
        char s2[] = "abcd";

        assert(s2 < s1);
    }

    {
        String s1("abcde");
        char s2 = 'a';

        assert(s2 < s1);
    }

    {
        String s1("abcde");
        String s2 = "abcde";

        assert(s1 <= s2);
    }
    std::cout << "Done testing < operator." << std::endl;
}