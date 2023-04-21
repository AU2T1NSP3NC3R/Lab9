#include "Part.h"

Part::Part(std::string inVal) {
	word = inVal;
	count = 1;
}

void Part::incr_count() {
	count++;
}

bool Part::operator<(const Part& inVal) {
	return(this->word < inVal.word);
}

bool Part::operator>(const Part& inVal) {
	return(this->word > inVal.word);
}

bool Part::operator!=(const Part& inVal) {
	return(this->word != inVal.word);
}

bool Part::operator==(const Part& inVal) {
	return(this->word.compare(inVal.word) == 0);
}

