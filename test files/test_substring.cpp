//tests substring

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("egg is a dog");

        String s2 = s1.substr(0, 2);

        assert(s2 == "egg");
    }

    {
        String s1("egg is a dog");

        String s2 = s1.substr(4, 5);

        assert(s2 == "is");
    }

    {
        String s1("egg is a dog");

        String s2 = s1.substr(9, 11);

        assert(s2 == "dog");
    }
    std::cout << "Done testing substring." << std::endl;
}