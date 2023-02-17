#pragma once
#include <string>
#include "TextParser.h"
#include "Timer.h"
 class SortingAlgorithms{
public:
	static void BubbleSort(token[], int);
	static void InsertionSort(token[], int);
	static void SelectionSort(token[], int);
	static void MergeSort(token[], int, int);
	static void QuickSort(token[], int, int);
	
	static void CopyString(token[], token[], int);
};
