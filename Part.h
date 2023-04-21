#pragma once
#include <string>
#include <iostream>

class Part
{
	public:
		Part(std::string);

		void incr_count();

		std::string word;
		int count;

		bool operator<(const Part&);
		bool operator>(const Part&);
		bool operator!=(const Part&);
		bool operator==(const Part&);

		friend std::ostream& operator<<(std::ostream& os, const Part& inVal) {
			os << inVal.word;
			return os;
		}





};

