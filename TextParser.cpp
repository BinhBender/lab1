#include "TextParser.h"
#include <unordered_map>

TextParser(){
	
}
	//constructor for file
TextParser(std::string fileName){
		ifile.open(fileName);
}
	//delete the new memory when it goes out of scope
~TextParser();
bool TextParser::Parse(int limit){
	//check if the file is open or not before use
	if(!ifile.is_open()) return false;
	
	//creates a map for prohibited words.
	std::unordered_map<std::string, char> prohibited_words;
	prohibited_words['an'] = 1;
	prohibited_words['a'] = 1;
	prohibited_words['the'] = 1;
	prohibited_words['be'] = 1;
	
	//loops through the file for each word
	while(ifile){
		std::string word;
		ifile >> word;
		
		//check if the word is one of the prohibited
		if(prohibited_words[word] == 0){
		
			//increases the size per loop
			wordCount++;
			
			//uses the size to make a dynamically allocated array
			tokens = new std::string[wordCount];
			tokens[wordcount - 1] = word;
		}
				
	}
	
}
