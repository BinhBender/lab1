#include "Algorithms.h"
#include "Timer.h"
#include <iostream>
#include <string>
#include <iomanip>
#pragma once
//make a pair of values
//(could've used <Utilities> but seemed unnecessary)
//This class should comprise of analytical tools observing data of
// the sorting algorithms.
struct doublePair{
	double x;
	double y;
};

class AlgoTest {
	
private:
	const int testNumber = 5;
	double durationUnsort, durationSort;
	std::string* placeHolder;
	int lastSize;
	doublePair* listOfDurations;
public: 
//each test will consist of the unsorted and unsorted array
	AlgoTest();
	~AlgoTest();
	void BubbleSortTest		(TextParser&);
	void SelectionSortTest	(TextParser&);
	void InsertionSortTest	(TextParser&);
	void QuickSortTest		(TextParser&);
	void MergeSortTest		(TextParser&);
	
	std::string* GetStringArray();
	doublePair GetLastSortedDurationPair(); //Get a pair of timings for the unsorted and sorted.
	
	void PrintFirstLast(std::string* strs, int size);
	void PrintTime();
	void PrintFinalResults();
	void ExpectedOutComeN2(double baseTime, double shortSize, double longSize);
	void ExpectedOutComeNLogN(double baseTime, double shortSize, double longSize);
};
