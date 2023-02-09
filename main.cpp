#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <random>
#include "Timer.h"
#include "Algorithms.h"
#include "TextParser.h"
void SortAllAlgorithms(std::string*);
void SortTwoAlgorithms(std::string*);
//main should only be the "gui" and should not have any of the algorithms explicitly
int main(){
	
	//parse through a text file
	//tokenize the sentences so that each word is its own string
	//if any of characters like ' or `~ is adjacent to other chars, include them
	//otherwise remove any strays of them.
	
	//when checking for the alphabetical order of the characters
	//check the ascii of the characters
	//lower = better
	//if the chars are the same, go to the next char position
	//if string A runs out of chars before string B, choose the shorter one
	
	//Quick--
	//Quickly
	
	//make function for timing

	std::cout << "Hello User! Would you like to try and see the speed and efficiencies of some famous sorting algorithms?"<< std::endl;
	std::cout << "Y/N";
	char choice;
	std::cin >> choice;
	
	TextParser TP;
	TP.Parse("beemoviescript.txt");
	
	
	while(choice == 'Y'){
	//ask for choice between all alogrithms or just two random ones
		std::cout << "1- All Algorithms\n2-Two Random Algorithms";
		//repeat turns off
		bool repeat = true;
		while(repeat){
			
			char algoChoice;
			std::cin >> algoChoice;
			switch (algoChoice){
				case 1:
				repeat = false;
				break;
				case 2:
				repeat = false;
				break;
				default:
				//repeat
				
				std::cout << "Please Choose a Valid Option\n";
				break;
			}
		}
	}
	//Insertion sort
	//Selection Sort
	//Merge Sort
	//Quick Sort
	
}

void SortAllAlgorithms(std::string* s){
	//each algorithm needs at least 4 sorts
	//one for an unsorted array
	//one for a sorted array
	//one longer unsorted array
	//one longer sorted array
	};
void SortTwoAlgorithms(std::string* s){
	//first random nlogn
	int random = std::rand() % 2;
	Timer t;
	switch(random){
		case 0:
		//merge sort
		std::cout << "Merge Sort" << std::endl;
		t.StartTime();
		
		t.EndTime();
		break;
		case 1:
		//Quick Sort
		break;
	};
	//second random n^2 
	random = std::rand() % 3;
	switch(random){
		case 0:
		//Selection Sort
		break;
		case 1:
		//Insertion Sort
		break;
		case 2:
		//Bubble Sort
		//Algorithms::BubbleSort();
		
		break;
	};
}
