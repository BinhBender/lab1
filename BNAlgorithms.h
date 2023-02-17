#pragma once
#include <string>
#include "BNTextParser.h"
#include "BNTimer.h"
 class SortingAlgorithms{
public:
	static void BubbleSort(token[], int);
	static void InsertionSort(token[], int);
	static void SelectionSort(token[], int);
	static void MergeSort(token[], int, int);
	static void QuickSort(token[], int, int);
	
	static void CopyString(token[], token[], int);
};
