#pragma once
#include <string>
#include "TextParser.h"
#include "Timer.h"
class SortingAlgorithms{
public:
	static void BubbleSort(std::string[], int);
	static void InsertionSort(std::string[], int);
	static void SelectionSort(std::string[], int);
	static void MergeSort(std::string[], int, int);
	static void QuickSort(std::string[], int, int);
	
	static void CopyString(std::string[], std::string[], int);
};
