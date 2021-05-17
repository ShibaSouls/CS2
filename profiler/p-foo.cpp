#include "profile.hpp"
profile foo_cpp("foo.cpp");
void foo(int x) { foo_cpp.count(__LINE__, "foo"); 

    ++x; foo_cpp.count(__LINE__); 

}

