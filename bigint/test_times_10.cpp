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
        bi = bi.times10(1);

        // Verify
        assert(bi == 30);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 300);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(3);

        // Verify
        assert(bi == 3000);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(4);

        // Verify
        assert(bi == 30000);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("3");

        // Test 
        bi = bi.times10(8);

        // Verify
        assert(bi == 300000000);  
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("3");
	bigint b2("30000000000000000000000000000000000000000");
        // Test 
        bi = bi.times10(40);

        // Verify
        assert(bi == b2);  
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}

