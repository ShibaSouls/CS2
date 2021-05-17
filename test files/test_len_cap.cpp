//tests length and capacity

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    
    {
    String str("1234");

    assert(str.length() == 4);
    }

    {
    String str('a');

    assert(str.length() == 1);
    }

    {
    String str("It's egg time");

    assert(str.length() == 13);
    }

  std::cout << "Done testing length." << std::endl;

    {
    String str1;
                                                                               
    assert(str1.capacity() == 0);
    }

    { 
    String str1("abcdefghijklmnopqrstuvwxyz");

    assert(str1.capacity() == 26);
    }

    {                                                             

    String str1("1234567890");                                                                  

    assert(str1.capacity() == 10);
    }

  std::cout << "Done testing capacity." << std::endl;
}
