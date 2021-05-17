//test subscript

#include <iostream>
#include "string.hpp" 
#include <cassert>

int main ()
{
  {
    String str;

    assert(str[0] == '\0');
  }

  {
    String str('a');

    assert(str[0] == 'a');
  }

  {
    String str("a");

    std::cerr << str[0];
  }

  {
    String str("3000 chickens in my house");
  }
  std::cout << "Done testing subscript." << std::endl;
}