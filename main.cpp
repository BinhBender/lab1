#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <random>
#include "Timer.h"
#include "Algorithms.h"
#include "TextParser.h"
#include "AlgoTest.h"
#define PARSE_SIZE 5000
#define WIDTH 10
void SortAllAlgorithms(TextParser&, TextParser&);
void SortTwoAlgorithms(TextParser&, TextParser&);
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
	


	std::cout << "Hello User! Would you like to try and see the speed and efficiencies of some famous sorting algorithms?"<< std::endl;
	std::cout << "Y/N: ";
	char choice;
	std::cin >> choice;
	
	TextParser text1("beemoviescript.txt");
	text1.Parse(10);
	AlgoTest algoTest;
	for(int i = 0; i < 10 ; i++){
		std::cout << text1.GetToken()[i] << std::endl;
	}
	std::cout << "QuickSort\n";
	int a;
	std::cin >> a;
	SortingAlgorithms::QuickSort(text1.GetToken(), 1, 5);
	
	for(int i = 0; i < 10;i++){
		std::cout << text1.GetToken()[i] << std::endl;
	}
	//algoTest.QuickSortTest(text1);
	//algoTest.PrintTime();
	//algoTest.QuickSortTest(longText);
	//algoTest.PrintTime();
	//std::cout << std::endl;
	
	//algoTest.PrintFirstLast();
	/*
	TextParser text2("RomeoAndJuliet.txt");
	text2.Parse(PARSE_SIZE * 5);
	
	while(choice == 'Y'){
	//ask for choice between all alogrithms or just two random ones
		std::cout << "1- All Algorithms\n2-Two Random Algorithms\n";
		
		//repeat turns off
		bool repeat = true;
		while(repeat){
			
			int algoChoice;
			std::cin >> algoChoice;
			switch (algoChoice){
				case 1:
				SortAllAlgorithms(text1, text2);
				repeat = false;
				break;
				case 2:
				SortTwoAlgorithms(text1, text2);
				repeat = false;
				break;
				default:
				//repeat
				
				std::cout << "Please Choose a Valid Option\n";

			}
		}
		std::cout << "Would you like to run the program again?\n";
		std::cout << "Y/N: ";
		std::cin >> choice;
	}
	//Insertion sort
	//Selection Sort
	//Merge Sort
	//Quick Sort*/
	
}

void SortAllAlgorithms(TextParser& shortText, TextParser& longText){

	//each algorithm needs at least 4 sorts
	//one for an unsorted array
	//one for a sorted array
	//one longer unsorted array
	//one longer sorted array	
	AlgoTest algoTest;
	
	
	std::cout << std::setw(WIDTH * 2) <<std::right << "Unsorted";
	std::cout << std::setw(WIDTH + 1) <<  "Sorted\n";
	
	std::cout << "Bubble Sort\n";
	algoTest.BubbleSortTest(shortText);
	algoTest.PrintTime();
	algoTest.BubbleSortTest(longText);
	algoTest.PrintTime();
	std::cout << std::endl;
	
	std::cout << "Insertion Sort\n";
	algoTest.InsertionSortTest(shortText);
	algoTest.PrintTime();
	algoTest.InsertionSortTest(longText);
	algoTest.PrintTime();
	std::cout << std::endl;
	
	
	std::cout << "Selection Sort\n";
	algoTest.SelectionSortTest(shortText);
	algoTest.PrintTime();
	algoTest.SelectionSortTest(longText);
	algoTest.PrintTime();
	std::cout << std::endl;
	
	
	std::cout << "Merge Sort\n";
	algoTest.MergeSortTest(shortText);
	algoTest.PrintTime();
	algoTest.MergeSortTest(longText);
	algoTest.PrintTime();
	std::cout << std::endl;
	
	
	std::cout << "QuickSort\n";
	algoTest.QuickSortTest(shortText);
	algoTest.PrintTime();
	algoTest.QuickSortTest(longText);
	algoTest.PrintTime();
	std::cout << std::endl;
	
	algoTest.PrintFirstLast();
};
	
void SortTwoAlgorithms(TextParser& shortText, TextParser& longText){
	//first random nlogn
	int random = std::rand() % 2;
	
	std::cout << std::setw(WIDTH * 2) <<std::right << "Unsorted";
	std::cout << std::setw(WIDTH + 1) <<  "Sorted\n";
	
	AlgoTest algoTest;
	
	switch(random){
		case 0:
		//merge sort
		std::cout << "Merge Sort" << std::endl;
			std::cout << "Merge Sort\n";
			algoTest.MergeSortTest(shortText);
			algoTest.PrintTime();
			algoTest.MergeSortTest(longText);
			algoTest.PrintTime();
		
		break;
		case 1:
		//Quick Sort
			std::cout << "QuickSort\n";
			algoTest.QuickSortTest(shortText);
			algoTest.PrintTime();
			algoTest.QuickSortTest(longText);
			algoTest.PrintTime();
		
		break;
	}
	//second random n^2 
	random = std::rand() % 3;
	switch(random){
		case 0:
		//Selection Sort
			std::cout << "Selection Sort\n";
			algoTest.SelectionSortTest(shortText);
			algoTest.PrintTime();
			algoTest.SelectionSortTest(longText);
			algoTest.PrintTime();
		break;
		case 1:
		//Insertion Sort
			std::cout << "Insertion Sort\n";
			algoTest.InsertionSortTest(shortText);
			algoTest.PrintTime();
			algoTest.InsertionSortTest(longText);
			algoTest.PrintTime();	
		break;
		case 2:
		//Bubble Sort
			std::cout << "Bubble Sort\n";
			algoTest.BubbleSortTest(shortText);
			algoTest.PrintTime();
			algoTest.BubbleSortTest(longText);
			algoTest.PrintTime();
		
		break;
	}
	
	
	algoTest.PrintFirstLast();
}
