// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 9);
      assert(result == 9);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(99);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 99);
      assert(result == 100);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(10);
      bigint right(999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10);
      assert(right  == 999);
      assert(result == 1009);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(100);
      bigint right(1000);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 100);
      assert(right  == 1000);
      assert(result == 1100);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(1000);
      bigint right(10000);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1000);
      assert(right  == 10000);
      assert(result == 11000);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(10000);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10000);
      assert(right  == 1);
      assert(result == 10001);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(10000);
      bigint right(100);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10000);
      assert(right  == 100);
      assert(result == 10100);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(9999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 9999);
      assert(result == 9999);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(99999);
      bigint right(10000);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 99999);
      assert(right  == 10000);
      assert(result == 109999);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(6);
      bigint right(100);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 6);
      assert(right  == 100);
      assert(result == 106);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(999);
      bigint right(100000);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999);
      assert(right  == 100000);
      assert(result == 100999);
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left("99");
      bigint right("1234567891011");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "99");
      assert(right  == "1234567891011");
      assert(result == "1234567891110");
    }

    {
    //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right("1234567891011");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == "1234567891011");
      assert(result == "1234567891011");
    }

    //assert(1 == 2); //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
}

