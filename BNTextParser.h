#pragma once
#include <fstream>
#include <string>
//given an text file, it the class should be able to tokenize
//the sentences, making an array that would have individual words.

//eliminate all "a", "an", "be", "the"
//should be able to "clean" the words
//	removes commas periods parentheses
struct token{
	std::string NormWord;
	std::string lowerCaseWord;
};
class TextParser{
	//this will most likely take the longest
	
private:
	int wordCount;
	std::ifstream ifile;
	token* tokens;
public:
	TextParser();	//constructor for file
	TextParser(std::string);
	~TextParser();	//delete the new memory when it goes out of scope
	token* GetToken();
	int GetSize();
	bool Parse(int limit);
	
};
