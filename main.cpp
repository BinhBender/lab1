#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "Timer.h"
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
	//Timer t;
	//t.StartTime();
	std::cout << "Hello User! Would you like to try and see the speed and efficiencies of some famous sorting algorithms?"<< std::endl;
	std::cout << "Y/N";
	char choice;
	std::cin >> choice;
	
	if(choice == 'Y'){
	//ask for choice between all alogrithms or just two random ones
		std::cout << "1- All Algorithms\n2-Two Random Algorithms";
		char algoChoice;
		std::cin>> algoChoice;
		switch (algoChoice){
			case 1:
			
			break;
			case 2:
			
			break;
			default:
			//repeat
			
			std::cout << "Please Choose a Valid Option\n";
			break;
		}
	}
	//std::cout << t.EndTime().count();
	//Insertion sort
	//Selection Sort
	//Merge Sort
	//Quick Sort
	
}

