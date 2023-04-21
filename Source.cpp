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

	while (line != "") {	// loads all of MobyDick.txt into the binary tree
		while (pos <= line.length()) {
			for (int i = start; i < line.length(); i++) {	// increments pos to end of word
				if (isalpha(line[i])) {
					pos++;
				}
				else {
					break;
				}
			}
			word = line.substr(start, (pos-start));	// creates word for object 
			start = pos+1;
			pos = pos+1;

			Part* toAdd = new Part(word);
			std::cout << toAdd->word << std::endl;
		
			Part* checker = myTree.find(toAdd);
			if (checker == nullptr) {	// object isnt in tree
				myTree.publicInsert(toAdd);
			}
			else {	// object is in tree, and increments count
				checker->incr_count();
			}
		}
		getline(moby, line);
		pos = 0;
		start = 0;
	}

	char userInp = 'y';
	std::string toFind = "";

	while (userInp != 'n' && userInp != 'N') {


		std::cout << "| (1): Find a word within the tree" << std::endl;
		std::cout << "| (2): Print all the words in the tree in ascending order" << std::endl;
		std::cout << "| (3): Print all the words in the tree in descending order" << std::endl;
		std::cout << " Pick (1, 2, 3) from the options above: ";
		std::cin >> userInp;

		if (userInp == '1') {
			std::cout << "| Enter a word to find in the tree: ";
			std::cin >> toFind;
			std::cout << std::endl;

			Part* plop = new Part(toFind);

			Part* found = myTree.find(plop);
			if (found == nullptr) {
				std::cout << "The word you entered was not in the tree" << std::endl;
			}
			else {
				std::cout << "The word appears " << found->count << " times within the tree" << std::endl;
			}
		}
		else if (userInp == '2') {
			myTree.publicGetAllAscending();
		}
		else if (userInp == '3') {
			myTree.publicGetAllDescending();
		}
	}



	return 0;
}
