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
	std::string tokens;
	TextParser();
	//constructor for file
	TextParser(string fileName);
	
	bool Parse(){
		//check if the file is open or not before use
		if(!ifile.is_open()) return false;
		
		//loops through the file for each word
		while(ifile){
			std::string dummy;
			ifile >> dummy;
			
			if(dummy.size() == 1) 
		}
	
	}
	
};
