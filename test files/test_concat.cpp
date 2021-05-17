//tests concat

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String s1("dog");

        String s2 = s1 + "animal";

        assert(s2 == "doganimal");
    }

    {
        String s1("dog");

        String s2 = s1 + 'a';

        assert(s2 == "doga");
    }

    {
        String s1("dog");

        s1 += "animal";
    	  
        assert(s1 == "doganimal");
    }

    {
        String s1("dog");
        String s2("");
        s1 += s2;

        assert(s1 == "dog");
    }

    {
        String s1("");
        String s2("dog");
        s1 += s2;

        assert(s1 == "dog");
    }

    {
        String s1("");
        String s2("");
        s1 += s2;

        assert(s1 == "");
    }

    {
        String s1("abc");
        String s2("");
        String s3 = s1 + s2;

        assert(s3 == "abc");
    }

    {
        String s1("");
        String s2("");
        String s3 = s1 + s2;

        assert(s3 == "");
    }
    
    {
        String s1("");
        String s2("abc");
        String s3 = s1 + s2;

        assert(s3 == "abc");
    }
    std::cout << "Done testing concat." << std::endl;
}