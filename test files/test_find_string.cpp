// tests find string

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("toy is a dog");

        int location = s1.findstr(0, "toy");

        assert(location == 0);
    }

    {
        String s1("toy");

        int location = s1.findstr(0, "oy");

        assert(location == 1);
    }

    {
        String s1("toy");

        int location = s1.findstr(0, 'y');

        assert(location == 2);
    }

    {
        String s1("toy");

        int location = s1.findstr(0, 'a');

        assert(location == -1);
    }

    {
        String s1("toy is a dog");

        int location = s1.findstr(0, "is");

        assert(location == 4);
    }

    {
        String s1("toy is a dog");

        int location = s1.findstr(6, "is");

        assert(location == -1);

    }

	{
        String s1("toy is a dog");

        int location = s1.findstr(1, "toy");

        assert(location == -1);
    }
    std::cout << "Done testing findstr." << std::endl;
}
