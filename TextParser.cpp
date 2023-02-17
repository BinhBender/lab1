#include "TextParser.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cctype>
//Returns how many words the parser is storing
int TextParser::GetSize(){
	return wordCount;
}
//set the default values
TextParser::TextParser(){
	wordCount=0;
	tokens = nullptr;
}
	//constructor for file
TextParser::TextParser(std::string fileName){
	std::cout << "Finding File...";
	ifile.open(fileName);
	std::cout << "\nFound File!\n";
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
	std::cout << "Starting Parse... ";
	if(!ifile.is_open()) return false;
	//creates a dynamic array based on the limit size
	//this array will be shrunken if the wordcount < limit
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
		//place holder variables
		std::string word;
		std::string lcWord;
		token a;
		
		/*
		This loop checks the lowercase of the word to see if
		its a prohibited word if it is then it keeps looping until its not.
		*/
		do {

				
			ifile >> word;
			word = removePunctuation(word); //cleans the word
			lcWord = lowerCaseCheck(word);  //turn into lowercase
			
		}while(prohibited_words[lcWord] == 1);
		//since map creates a hash for every index its given, we have to
		//remove it to conserve memory
		prohibited_words.erase(lcWord);
		
		//wordCount = size but is not =/= to index position 
		
		wordCount++;
		tokens[wordCount - 1].NormWord = word;
		tokens[wordCount - 1].lowerCaseWord = lcWord;
		
	}
	
	//checks if the txt file is finished parsing before it reached the limit
	//this would mean that the inital array was too big so we make a new one
	//thats in accordance to how much was filled up and copy them over.
	if(wordCount< limit){
		token* dummy = tokens;
		tokens = new token[wordCount];
		for(int i = 0; i < wordCount; i++){
			tokens[i] = dummy[i];
		}
		delete[] dummy; 
	}
	std::cout << "Parse of: " << wordCount << " ended\n";
	return true;
	
}

//returns the array
token* TextParser::GetToken(){
	return tokens;
}
