#include "TextParser.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cctype>
int TextParser::GetSize(){
	return wordCount;
}

TextParser::TextParser(){
	wordCount=0;
	tokens = nullptr;
}
	//constructor for file
TextParser::TextParser(std::string fileName){
	std::cout << "Finding File\n";
	ifile.open(fileName);
	std::cout << "Found File\n";
	wordCount = 0;
	tokens = nullptr;
}

//delete the new memory when it goes out of scope
TextParser::~TextParser(){
	delete[] tokens;
}

//clean the word first (no puncutation marks)
std::string removePunctuation(std::string input){
	int size = input.length();
	std::string output;
	for(int i = 0; i < size; i++){
		char c = input[i];
		//checks if char is an alphabetical letter or not
		//checks for exceptions first
		if(isalpha(c)){
			output += c;
		}else if(c == 39 || c == '-'){
			//checks if the numbers are below or
			//above the domain of the string
			int upper = (i + 1 > size-1) ? i : i+1;
			int lower = (i - 1 < 0) ? i : i - 1;
			//if at least one is true, then were can be sure that its a word
			//doesn't, chess', half-life
			//checks c within the bound and this should return true
			//when both sides are F
			if(isalpha(input[upper]) || isalpha(input[lower])){
				output += c;
			}
		}
		
	}
	return output;
}
std::string lowerCaseCheck(std::string a){
	
	std::transform(a.begin(),a.end(),a.begin(), ::tolower);
	
	return a;
}
bool TextParser::Parse(int limit){
	//check if the file is open or not before use
	std::cout << "Starting Parse\n";
	if(!ifile.is_open()) return false;
	tokens = new token[limit];
	//creates a map for prohibited words.
	std::unordered_map<std::string, char> prohibited_words;
	prohibited_words["an"] = 1;
	prohibited_words["a"] = 1;
	prohibited_words["the"] = 1;
	prohibited_words["be"] = 1;
	prohibited_words[" "] = 1;
	prohibited_words["\n"] = 1;
	
	//loops through the file for each word until it 
	while(ifile && wordCount < limit){
		std::string word;
		std::string lcWord;
		token a;
		do {


			ifile >> word;
			word = removePunctuation(word);
			lcWord = lowerCaseCheck(word); 
			
		}while(prohibited_words[lcWord] == 1);
		prohibited_words.erase(lcWord);
		
		tokens[wordCount].NormWord = word;
		tokens[wordCount].lowerCaseWord = lcWord;
		
		wordCount++;
	}
	
	if(wordCount + 1 < limit){
		token* dummy = tokens;
		tokens = new token[wordCount];
		for(int i = 0; i < wordCount; i++){
			tokens[i] = dummy[i];
		}
		delete[] dummy; 
	}
	std::cout << "Size:" << wordCount;
	return true;
	
}


token* TextParser::GetToken(){
	return tokens;
}
