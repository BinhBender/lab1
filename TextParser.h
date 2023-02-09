#pragma once
#include <fstream>
#include <string>
//given an text file, it the class should be able to tokenize
//the sentences, making an array that would have individual words.

//eliminate all "a", "an", "be", "the"
//should be able to "clean" the words
//	removes commas periods parentheses
class TextParser{
	//this will most likely take the longest
	
private:
	int wordCount;
	std::istream ifile;
	std::string* tokens;
	
public:
	TextParser();
	//constructor for file
	TextParser(std::string);
	//delete the new memory when it goes out of scope
	~TextParser();
	
	
	bool Parse(int limit);
	
};
