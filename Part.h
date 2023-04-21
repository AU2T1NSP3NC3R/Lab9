#pragma once
#include <string>



class Part
{
	public:
		Part(std::string);

		void incr_count();

		std::string word;
		int count;

		bool operator<(const Part&);
		bool operator>(const Part&);
		bool operator==(const Part&);




};

