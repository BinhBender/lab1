#pragma once
#include <fstream>
#include <string>
//given an text file, it the class should be able to tokenize
//the sentences, making an array that would have individual words.

//eliminate all "a", "an", "be", "the"
class TextParser{
	//this will most likely take the longest
	int wordCount;
	std::istream ifile;
	std::string 
	TextParser();
	//constructor for file
	TextParser(string fileName);

};
