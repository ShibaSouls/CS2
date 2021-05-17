// tests split

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    {
        String str = "Hello-world-!";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;

        assert(result.size() == 3);
    
    }

    {
        String str = "Hello--world-!";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;;
        assert(result.size() == 4);
    }

    {
        String str = "-a--b-";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
        std::cout << result[3] << std::endl;  
  
        assert(result.size() == 5);
    }

    {
        String str = "a--b";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;

        assert(result.size() == 3);
    }

    {
        String str = "a--b";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
       
        assert(result.size() == 3);
    }

     {
        String str = "This is a test!";
        std::vector<String> result;
        
        result = str.split(' ');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 4);
    }   

     {
        String str = "This is a-test!";
        std::vector<String> result;
        
        result = str.split(' ');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 3);
    }  

    {
        String str = "-a--b-";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 5);
    }

    {
        String str = "-a--b-c";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 5);
    }
}