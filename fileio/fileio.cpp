#include <iostream>
#include <fstream>
#include <string>
#include "../includes/fileio.h"
#include "../includes/constants.h"
using namespace std;

/**
 * Reads info from filename into contents
 *
 * \param filename where data is
 * \param contents data to write to file
 * \return
 *        FAIL_CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename,std::string &contents){
	std::string line;
	ifstream inputFile;
	inputFile.open(filename.c_str(), ios::in);

	if (inputFile.is_open()){
		getline(inputFile, line);
		contents = line;
		return SUCCESS;
	}
	return FAIL_CANNOT_OPEN_FILE;
}

/**
 * write data in contents to filename
 *
 * \param filename: where data will go, overwrite if already there
 * \param contents: data to write to filename
 *        hint:  you can get a const char * by calling the method .c_str() on a std::string
 * \return
 *        INVALID_NULL_PTR_DETECTED if contents ==NULL
 *        SUCCESS otherwise
 */
int writeFile(std::string &filename,char *contents) {
	if (contents == NULL){
			return INVALID_NULL_PTR_DETECTED;
		}
	ofstream outputFile;
	outputFile.open(filename.c_str(), ios::out);

	outputFile.clear();
	outputFile << contents;
	outputFile.close();
	return SUCCESS;




}
