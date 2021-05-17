// implementation for fileio
// Livia Coduto
// 2/11/2021

#include <iostream>
#include <fstream>

void readText () {
    std::ifstream file("fileio-text.txt");
    
    if(!file.is_open()) {
        std::cout << "Unable to access file.";
    }

    char c;
    file.get(c);
    while(c != ' ') {
        std::cout << c ;
        file.get(c);
    }
    file.close();
}

void addTwo() {
    std::ifstream file2("fileio-data-1.txt");

    if(!file2.is_open()){
        std::cout << "Unable to access file";
    }

    int i = 0;
    int j = 0;
    char c;
    int result = 0;

    file2 >> i;
    file2.get(c);
    file2 >> j;
    result = i + j;

    std::cout << "Result is: " << result;

    file2.close();

}

int main() {
    readText();
    addTwo();
}