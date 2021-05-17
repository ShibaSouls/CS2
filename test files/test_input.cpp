// tests input

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

  {                                                                                  
    std::cout << "INPUT TEST -- please type: howdy" << std::endl;
    String str;

    std::cin >> str;                                                                                 

    assert(str == "howdy");
  }
  std::cout << "Done testing input." << std::endl;
}