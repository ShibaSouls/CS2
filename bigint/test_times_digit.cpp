// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 12);  //Will FAIL, fix and add test cases.
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(10);

        // Verify
        assert(bi == 30);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(100);

        // Verify
        assert(bi == 300);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1000);

        // Verify
        assert(bi == 3000);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(100000);

        // Verify
        assert(bi == 300000);  
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
}