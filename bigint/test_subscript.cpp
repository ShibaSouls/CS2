// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //fixed test case
        assert(digit == 4);
    }

    {
        // Setup
        bigint bi(1234);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 1234);  //added test case
        assert(digit == 2);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

