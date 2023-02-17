#include "BNAlgoTest.h"
#include <math.h>
AlgoTest::AlgoTest(){
	durationUnsort = 0;
	durationSort = 0;
	
	//create an empty array so the sorting tests can delete preemtively
	placeHolder = nullptr;
	listOfDurations = nullptr;
}

AlgoTest::~AlgoTest(){
	delete[] placeHolder;
	delete[] listOfDurations;
}
token* AlgoTest::GetStringArray(){
	return placeHolder;
}
void AlgoTest::PrintTime(){
	const int width = 20;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::setw(width * 3 + 1) << std::setfill('=') << '\n' << std::setfill(' ');
	std::cout << std::setw(width) << std::left << "Time (ms): " << std::right;
	std::cout << std::setw(width) << durationUnsort << std::setw(width) << durationSort << std::endl;

}       
double percentError(double experimentValue, double testedValue){
	return (experimentValue - testedValue) / testedValue;
	}
void AlgoTest::ExpectedOutComeN2(double baseTime, double shortSize, double longSize){
	//Need to find how much an algorithm
	//scales by given an inital time
	//so this finds that ratio
	double c = baseTime / (shortSize * shortSize);
	
	//multiply the ratio by the number of elements
	//in accordance to the O(n) type
	c*= longSize * longSize;
	std::cout << "For an algorithm of O(n^2) given the base time of " << baseTime << "ms \na scaled up time for a size of n * 5 \nwould be expected to be around " << c;
	std::cout << "\nAnd the % error is " << percentError(c,longSize);
}
void AlgoTest::ExpectedOutComeNLogN(double baseTime, double shortSize, double longSize){
	//same thing as ExpectedOutComeN2()
	double c = baseTime / (shortSize * log(shortSize));
	c*= longSize * log(longSize);
	std::cout << "For an O(nlogn) given the base time of " << baseTime << "ms \na scaled up time for a size of n * 5 \nwould be expected to be around " << c;
	std::cout << "\nAnd the % error is " << percentError(c,longSize) << "%\n";
}
void AlgoTest::PrintFirstLast(token* strs, int size){
	//make two loops to print first 50 of the array
	//and last 50
	
	int endline = 0; //counter to add an std::endl every few words
	std::cout << "====First 50 Words====\n";
	for(int i = 0; i < 50; i++){
		std::cout << strs[i].NormWord << ", ";			   //new line every few words
		endline++;
		if(endline % 15 == 0) std::cout<<std::endl;
	}
	
	std::cout << "\n====Last 50 Words====\n";
	for(int i = size - 51; i < size; i++){
		std::cout << strs[i].NormWord << ", ";
		endline++;		
		if(endline % 15 == 0) std::cout<<std::endl; //new line every few words
	}
}
doublePair AlgoTest::GetLastSortedDurationPair(){
	doublePair c;
	c.x = durationUnsort;
	c.y = durationSort;
	return c;
}
void AlgoTest::BubbleSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
	durationUnsort = 0;
	durationSort = 0;
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new token[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		time.StartTime();
		SortingAlgorithms::BubbleSort(placeHolder, lastSize);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again, for the final loop of the placeholder, 
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::BubbleSort(placeHolder, lastSize);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}

void AlgoTest::SelectionSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
		durationUnsort = 0;
	durationSort = 0;
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new token[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		time.StartTime();
		SortingAlgorithms::SelectionSort(placeHolder, lastSize);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again, for the final loop of the placeholder, 
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::SelectionSort(placeHolder, lastSize);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}
void AlgoTest::InsertionSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
		durationUnsort = 0;
	durationSort = 0;
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new token[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		time.StartTime();
		SortingAlgorithms::InsertionSort(placeHolder, lastSize);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again, for the final loop of the placeholder, 
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::InsertionSort(placeHolder, lastSize);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}
void AlgoTest::QuickSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
		durationUnsort = 0;
	durationSort = 0;
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new token[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		//test start
		time.StartTime();
		SortingAlgorithms::QuickSort(placeHolder, 0, lastSize - 1);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again, for the final loop of the placeholder, 
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::QuickSort(placeHolder,0, lastSize - 1);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}

void AlgoTest::MergeSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
	durationUnsort = 0;
	durationSort = 0;
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new token[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		//test start
		time.StartTime();
		SortingAlgorithms::MergeSort(placeHolder,0, lastSize - 1);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again,
	//it doesn't need be mutated since its already sorted
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::MergeSort(placeHolder,0, lastSize - 1);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}
