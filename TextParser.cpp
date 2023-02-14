#include "TextParser.h"
#include <unordered_map>
#include <iostream>

int TextParser::GetSize(){
	return wordCount;
}

TextParser::TextParser(){
	wordCount=0;
	tokens = new std::string[1];
}
	//constructor for file
TextParser::TextParser(std::string fileName){
	std::cout << "Finding File\n";
	ifile.open(fileName);
	std::cout << "Found File\n";
	wordCount = 0;
	tokens = new std::string[1];
}

//delete the new memory when it goes out of scope
TextParser::~TextParser(){
	delete[] tokens;
}

void removePunctuation(std::string& input){
	//clean the word first (no puncutation marks)
	for(long unsigned int i = 0; i < input.size(); i++){
		//if the char is not between ascii values of the letters
		//then it should be removed
		char c = input[i];
		if(c == 39){}
		else if((c > 32 && c < 65)|| (c > 90 && c < 97) || c > 122){
			input.erase(i);
		}
	}
}
bool TextParser::Parse(int limit){
	//check if the file is open or not before use
	std::cout << "Starting Parse\n";
	if(!ifile.is_open()) return false;
	
	//creates a map for prohibited words.
	std::unordered_map<std::string, char> prohibited_words;
	prohibited_words["an"] = 1;
	prohibited_words["a"] = 1;
	prohibited_words["the"] = 1;
	prohibited_words["be"] = 1;
	
	//loops through the file for each word until it 
	while(ifile && wordCount < limit){
		std::string word;
		ifile >> word;
		removePunctuation(word);
		//check if the word is one of the prohibited
		//but just in case there is more than one in a row
		//loop it
		while(prohibited_words[word] == 1) {
		//since a map inserts an element anytime it is accessed with
		//a different key, we need to remove it in order to save some 
		//memory since this is looking at a lot of words
			prohibited_words.erase(word);
			ifile >> word;
		}
		
		
		
			
		//increases the size per loop
		wordCount++;
		//make a placeholder pointer for the string array before deleting.
		std::string* dummy = tokens;
		
		//uses the size to make a dynamically allocated array
		tokens = new std::string[wordCount];
			
		//copy all of the words from the previous array into the new one.
		for(int i = 0; i < wordCount - 1; i++){
			tokens[i] = dummy[i];
		}
		//delete old array
		delete[] dummy;
			
		//insert new word into array.
		tokens[wordCount - 1] = word;
		
		
	}
	
	return true;
}


std::string* TextParser::GetToken(){
	return tokens;
}
