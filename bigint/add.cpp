// for milestone 2 of bigint project
// Livia Coduto
// 2/10/2021

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");
    if(!in) {
        std::cerr << "Could not open data1-1.txt." << std::endl;
        exit(1);
    }

	char wordOne[CAPACITY];
	char wordTwo[CAPACITY];

	while(!in.eof()) {
		if(in.getline(wordOne, CAPACITY, ';') && in.getline(wordTwo, CAPACITY, ';')){

			bigint b1(wordOne);
			bigint b2(wordTwo);

			bigint b3 = (b1 + b2);

			std::cout << "\n  " << b1 << std::endl;
			std::cout << "+ " << b2 << std::endl;
			std::cout << "= " << b3 << std::endl;
		}
	}

	if(in.eof()) {
		std::cout << "\nEND OF FILE REACHED " << std::endl;
	}

    in.close();

    return 0;
}