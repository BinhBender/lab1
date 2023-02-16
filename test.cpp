#include <iostream>
#include "Algorithms.h"
#include "TextParser.h"

int main(){
	TextParser tp("beemoviescript.txt");
	tp.Parse(1000);
	for(int i = 0; i < 100; i++){
		 std::cout << tp.GetToken()[i] << " ";
	}
	SortingAlgorithms::BubbleSort(tp.GetToken(),tp.GetSize());
	std::cout << std::endl << std::endl;
	std::string* text = tp.GetToken();
	for(int i = 0; i < 100; i++){
		 std::cout << text[i] << ", ";
	}
	
	return 0;
}
