// cpp file for project 1
// Livia Coduto
// 2/4/2021

#include "bigint.hpp"

// constructors
bigint::bigint () {
    for(int i = 0; i < CAPACITY; ++i) {
        bigIntArr[i] = 0;
    }
};

bigint::bigint (int userInput) {
    int i = 0;

    while (i < CAPACITY) {
        if (userInput > 0) {
            bigIntArr[i] = userInput % 10;
            userInput /= 10;
        }
        else {
            bigIntArr[i] = 0;
        }
        ++i;
        
    }
};

bigint::bigint (const char arr[]) {
    bool foundNull = false;
    int countChars = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        bigIntArr[i] = 0;
        if (arr[i] == '\0' || foundNull) {foundNull = true;}
        if (arr[i] != '\0' && !foundNull) {++countChars;}
    }

    for (int i = 0, j = countChars -1; i < countChars; ++i, --j) {
        if(arr[j] != ' ' && arr[j] != ';' && arr[j] != '\n' && arr[j] != '\r') {
            bigIntArr[i] = (int)(arr[j]) - 48;
        }
    }
}

// methods
bool bigint::operator== (const bigint& rhs) const {
    bool isEqual = true;

    for (int i = 0; i < CAPACITY; ++i) {
        if (bigIntArr[i] != rhs.bigIntArr[i]) {
            isEqual = false;
        }
    }

    return isEqual;
}

bigint bigint::operator+(const bigint& rhs) const {
	int carry = 0;
	int tmpValue = 0;
	bigint newBigInt;

	for (int i = 0; i < CAPACITY; ++i) {
		if (tmpValue >= 0 && carry == 0) {
			tmpValue = bigIntArr[i] + rhs.bigIntArr[i];
			newBigInt.bigIntArr[i] = tmpValue % 10;

			if( tmpValue >= 10) { carry = 1;}
		} else if (tmpValue == 0 && carry == 1) {
			tmpValue = bigIntArr[i] + rhs.bigIntArr[i] + carry;

			if (tmpValue >= 10) {
				newBigInt.bigIntArr[i] = tmpValue % 10;
				carry = 1;
			} else {
				newBigInt.bigIntArr[i] = tmpValue;
				carry = 0;
			}
 		}

		tmpValue = 0;
	}

	return newBigInt;
}

int bigint::operator[] (const int i) const {
	return bigIntArr[i];
}

bigint bigint::operator* (const bigint rhs) const {
	bigint product;

	for(int i = 0; i < CAPACITY; ++i) {
		product = product +(timesDigit(rhs.bigIntArr[i])).times10(i);
	}

	return product;
}

bigint bigint::timesDigit(int number) const{
	bigint tmp;
	int tmpValue = 0;
	int digitCarry = 0;

	for (int i = 0; i < CAPACITY; ++i) {
		if (tmpValue >= 0 && digitCarry == 0) {
			tmpValue = bigIntArr[i] * number;

			tmp.bigIntArr[i] = tmpValue % 10;

			if (tmpValue >= 10) {  digitCarry = tmpValue / 10;}

		} else if (tmpValue == 0 && digitCarry > 0) {
			tmpValue = bigIntArr[i] * number + digitCarry;

			tmp.bigIntArr[i] = tmpValue % 10;

			digitCarry = tmpValue / 10;
		}

		tmpValue = 0; 
	}

	return tmp;
}

bigint bigint::times10(int shift) const {
	bigint tmp;
	int endIndex = CAPACITY - 1;

	for (int i = endIndex; i >= 0; --i) {
		if( i <= endIndex - shift) {
			tmp.bigIntArr[i + shift] = bigIntArr[i];
		}
	}

	return tmp;
}

void bigint::debugPrint(std::ostream& out) const {
	for (int i = CAPACITY - 1; i >= 0; --i){
		out << bigIntArr[i];
		if (i > 0) {
			out  <<  "|";
		}
	}

	out << std::endl;
}

std::ostream& operator << (std::ostream& out,const bigint& b) {
	bool detectedNumbers = false;
	const int maxLineSize = 80;
	int currentLineSize = 0;

	for (int i = CAPACITY - 1; i >= 0; --i) {
		if (b.bigIntArr[i] > 0 && !detectedNumbers){
			out << b.bigIntArr[i];
			++currentLineSize;
			detectedNumbers = true;
		} else if (b.bigIntArr[i] >= 0 &&  detectedNumbers) {
			out << b.bigIntArr[i];
			++currentLineSize;
		} else if (i == 0 && !detectedNumbers){
			out << 0;
		}

		if(currentLineSize == maxLineSize) {
			out << std::endl;
			currentLineSize = 0;
		}
	}

	return out;
}

std::istream& operator >> (std::istream& in, bigint& b) {
	char str[CAPACITY];
	bool foundNull = false;
	int countOfChars = 0;

	in.getline(str, CAPACITY, ';');

	for (int i = 0; i < CAPACITY; ++i) {
		if (str[i] == '\0' || foundNull) {
			foundNull = true;
			b.bigIntArr[i] = 0;
		}

		if (str[i] != '\0' && !foundNull) { ++countOfChars; }
	}

	for (int i = 0, j = countOfChars -1; i < countOfChars; ++i, --j) {
		b.bigIntArr[i] = (int)(str[j]) - 48;
	}

	return in;
}