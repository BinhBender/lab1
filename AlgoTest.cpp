#include "AlgoTest.h"

AlgoTest::AlgoTest(){
	durationUnsort = 0;
	durationSort = 0;
	
	//create an empty array so the sorting tests can delete preemtively
	placeHolder = new std::string[1];
	listOfDurations = new doublePair[1];
}

AlgoTest::~AlgoTest(){
	delete[] placeHolder;
	delete[] listOfDurations;
}
std::string* AlgoTest::GetStringArray(){
	return placeHolder;
}
void AlgoTest::PrintTime(){
	const int width = 20;
	std::cout << std::setw(width * 3 + 1) << std::setfill('=') << '\n' << std::setfill(' ');
	std::cout << std::setw(width) << std::left << "Time: " << std::right;
	std::cout << std::setw(width) << durationUnsort << std::setw(width) << durationSort << std::endl;

}       
void AlgoTest::PrintFirstLast(){
	//make two loops to print first 50 of the array
	//and last 50
	
	int endline = 0; //counter to add an std::endl every few words
	std::cout << "====First 50 Words====\n";
	for(int i = 0; i < 50; i++){
		std::cout << placeHolder[i] << ", ";			   //new line every few words
		
		if(endline % 10 == 0) std::cout<<std::endl;
	}
	
	std::cout << "\n====Last 50 Words====\n";
	for(int i = lastSize - 51; i < lastSize; i++){
		std::cout << placeHolder[i] << ", ";
		
		if(endline % 10 == 0) std::cout<<std::endl; //new line every few words
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

	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new std::string[lastSize];
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
	
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new std::string[lastSize];
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
	
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new std::string[lastSize];
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
	
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new std::string[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		//test start
		time.StartTime();
		SortingAlgorithms::QuickSort(placeHolder,0, lastSize);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again, for the final loop of the placeholder, 
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::QuickSort(placeHolder,0, lastSize);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}

void AlgoTest::MergeSortTest(TextParser& Txt){
	Timer time;
	lastSize = Txt.GetSize();
	
	//Holds a copy of the string from the text parser so it could keep resorting.
	delete[] placeHolder;
	placeHolder = new std::string[lastSize];
	for(int i = 0; i < testNumber; i++){
		//copy the original array every single loop
		SortingAlgorithms::CopyString(Txt.GetToken(), placeHolder, lastSize);
		
		//test start
		time.StartTime();
		SortingAlgorithms::MergeSort(placeHolder,0, lastSize);
		durationUnsort += time.EndTime();
	}
	durationUnsort /= testNumber;
	
	//now for the sorted array
	//since the placeHolder doesn't reset until it loops again,
	//it doesn't need be mutated since its already sorted
	for(int i = 0; i < testNumber; i++){
		time.StartTime();
		SortingAlgorithms::MergeSort(placeHolder,0, lastSize);
		time.EndTime();
		durationSort += time.EndTime();
	}
	durationSort /= testNumber;
}
