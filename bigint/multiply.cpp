// for milestone 3 of project 1
// Livia Coduto
// 2/18/2021

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-2.txt");
    if(!in) {
        std::cerr << "Could not open data1-2.txt, exiting." << std::endl;
        exit(1);
    }

	char firstInt[CAPACITY];
	char secondInt[CAPACITY];

	while(!in.eof()) {
		if(in.getline(firstInt, CAPACITY, ';') && in.getline(secondInt, CAPACITY, ';')){

			bigint b1(firstInt);
			bigint b2(secondInt);

			bigint b3 = (b1 * b2);

			std::cout << "\n  " << b1 << std::endl;
			std::cout << "* " << b2 << std::endl;
			std::cout << "= " << b3 << std::endl;
		}
	}

	if(in.eof()) {
		std::cout << "\nEND OF FILE REACHED " << std::endl;
	}

    in.close();

    return 0;
}