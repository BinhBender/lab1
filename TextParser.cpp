#include "TextParser.h"
#include <unordered_map>

TextParser(){
	wordCount=0;
	tokens = new std::string[1];
}
	//constructor for file
TextParser(std::string fileName){
		ifile.open(fileName);
}
	//delete the new memory when it goes out of scope
~TextParser(){
	delete[] tokens;
}
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
		//clean the word first (no puncutation marks)
		for(int i = 0; i < word.size(); i++){
			//if the char is not between ascii values of the letters
			//then it should be removed
			char c = word[i];
			if((c > 32 && c < 65)|| (c > 90 && c < 97) || c > 122){
				word.erase(i);
			}
		}
		
		
		//check if the word is one of the prohibited
		if(prohibited_words[word] == 0){
		
			
			//increases the size per loop
			wordCount++;
			//delete the previously allocated array
			delete[] tokens;
			
			//uses the size to make a dynamically allocated array which then is immediately stored
			tokens = new std::string[wordCount];
			tokens[wordcount - 1] = word;
		}
				
	}
	
}
