#include "tree.h"
#include "tree.cpp"
#include "Part.h"
#include <fstream>

int main() {
	std::ifstream moby;
	moby.open("MobyDick.txt", std::ios::in);

	tree<Part> myTree = tree<Part>();
	
	std::string con = "";
	while (con != "Contents:") {
		getline(moby, con);
	}
	
	std::string line = "z";
	getline(moby, line);
	std::string word;
	int pos = 0;
	int start = 0;

	while (line != "") {
		while (pos <= line.length()) {
			for (int i = pos; i < line.length(); i++) {	// increments pos to end of word
				if (isalpha(line[i])) {
					pos++;
				}
				else {
					break;
				}
			}
			word = line.substr(start, pos);	// creates word for object 
			start = pos + 1;

			Part* toAdd = new Part(word);

			Part* checker = myTree.find(toAdd);
			if (checker == nullptr) {	// object isnt in tree
				myTree.publicInsert(toAdd);
			}
			else {	// object is in tree, and increments count
				checker->incr_count();
			}
		}
	}







	return 0;
}
