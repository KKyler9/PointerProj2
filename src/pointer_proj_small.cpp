//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"


int main(int argc, char *argv[]) {	
	//TODO Get commandline arguments
	if (argc == 2){
		char* help = argv[1];
			if (*help == HELP_CHAR){
				std::cout << HELP_STRING1 << HELP_STRING2 << endl;
				return SUCCESS;
			}
		}
		else if (argc != EXPECTED_NUMBER_ARGUMENTS){
			cout << HELP_STRING2 << endl;
			return FAIL_WRONG_NUMBER_ARGS;
		}
		std::string infile = argv[1];
		std::string outfile = argv[2];
		std::string tagSearch = argv[3];
		std::string replaceToken = argv[4];
	
	//TODO can we read file? Fail if not
		std::string contents;
	if(readFile(infile,  contents) != 0){
		return FAIL_CANNOT_OPEN_FILE;
	}

	//TODO how many tags found in file?


	int numb_tags = KP::findNumbOccurrences(contents.c_str(),tagSearch.c_str());

	//TODO how much memory to allocate?
	int memory = KP::amountOfMemoryToAllocateForNewString(strlen(contents.c_str()), numb_tags, strlen(tagSearch.c_str()), strlen(replaceToken.c_str()));
	char* newsrc = new char[memory];

	//TODO allocate memory

	//TODO replace original tag with new tags
	if(KP::replace(contents.c_str(), newsrc, tagSearch.c_str(), replaceToken.c_str()) != 0){
		return INVALID_NULL_PTR_DETECTED;
	}
	
	if(writeFile(outfile, newsrc) != 0) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	//TODO deallocate any memory allocated
	if(newsrc){
		delete [] newsrc;
		newsrc = NULL;
	}
}
