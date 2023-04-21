#pragma once
#include <string>

using namespace std;


class Object
{
	public:
		Object(string);

		void incr_count();

		string word;
		int count;

};

