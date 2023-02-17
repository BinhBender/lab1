#include "Algorithms.h"
#include <iostream>
#include <algorithm>

void swap(token& a, token& b){
	token temp = a;
	a = b;
	b = temp;
}

//helper function to find the lower alphabetical word
//returns true if a is "less than" b
//not used
int AlphabetValue(std::string str1, std::string str2){
	
	std::string a = str1;
	std::string b = str2;
	//to turn the string into a lower case
	std::transform(a.begin(),a.end(),a.begin(), [](unsigned char c) {return std::tolower(c); });
	std::transform(b.begin(),b.end(),b.begin(), [](unsigned char c) {return std::tolower(c); });
	
	//returns a positive when its lexicographically greater
	//returns a negative when its lexicographically less.
	return a.compare(b);
	
}


//o(n^2)
//Adapted from zybook
void SortingAlgorithms::BubbleSort(token strs[], int size){
	
	//nested loop since bubble sort is basically 
	//"for every i, check j"
	
	for(int i = 0; i < size; i++){
		/*
		incase the array is already sorted
		we assume that it is true
		and when a swap happens, 
		it means that its not sorted and so
		it switches to negative and keeps looping
		*/
		bool isSorted = true;
		for(int j = 1; j < size - i; j++){
			
			//if the j string is "less" than the prev string, swap.
			if(strs[j].lowerCaseWord < strs[j-1].lowerCaseWord) {
				
				swap(strs[j], strs[j-1]);
				isSorted = false;
			}
			
		}
		
		if(isSorted) {break;}
	}
}

//o(n^2)
//Adapted from zybook
void SortingAlgorithms::InsertionSort(token array[] , int size){
	for(int i = 1; i < size; i++){
		token next = array[i];
		int j = i;
		while (j > 0 && array[j - 1].lowerCaseWord > next.lowerCaseWord){
			array[j] = array[j - 1];
			j--;
		}
		array[j] = next;
	}	
}
int min_position(token array[],int from,int to){
	
	int min = from;
	//goes through array to find the minimum
	for(int i = from+1; i <= to; i++){
		//if element at index i < min, set min to index i
		if(array[i].lowerCaseWord < array[min].lowerCaseWord){
			min = i;
		}
	
	}
	return min;
}
//o(n^2)
//Adapted from zybook
void SortingAlgorithms::SelectionSort(token array[], int size){
	//the opposite of bubble
	//left to right
	for(int i = 0; i < size - 1; i++){
		//finds the next lowest number in the array
		int min = min_position(array, i, size - 1);
		
		swap(array[i], array[min]);
		
	}
}

//Adapted from zybook
void Merge(token strs[], int from, int mid, int to){
	//create a new array in order to make it easier.
	int size = to - from + 1;
	token* tempStorage = new token[size];
	//std::cout << "Merge\n";
	//loop through the new array with two "pointers" 
	//the pointers will start at from, and mid+1
	//pointers will compare with the values of each other
	//and the pointer that has the lower value will insert
	//that value into the new array and shift up once
	int ipointer = from;
	int jpointer = mid + 1;
	int j = 0;
	while((ipointer <= mid) && (jpointer <=to)){
		
		//if ipointer is less than jpointer, add value from 
		//ipointer otherwise add from jpointer.
		
		if(strs[ipointer].lowerCaseWord < strs[jpointer].lowerCaseWord){
			tempStorage[j] = strs[ipointer];
			ipointer++;
		}
		else{
			tempStorage[j] = strs[jpointer];
			jpointer++;
		}
		j++;
	}
	//fill leftover from left side
	while(ipointer <= mid){
		tempStorage[j] = strs[ipointer];
		ipointer++;
		j++;
	}
	//fill leftover from right side
	while(jpointer <= to){
		tempStorage[j] = strs[jpointer];
		jpointer++;
		j++;
	}
	
	//fill original array from tempStorge
	for(j = 0; j < size; j++){
		strs[from + j] = tempStorage[j];
	}
	
	delete[] tempStorage;
}
//o(nlogn)
void SortingAlgorithms::MergeSort(token strings[], int from, int to){
	if(from >= to) return;
	//std::cout <<"split ";
	int mid = (from + to) / 2;
	MergeSort(strings,from, mid);
	MergeSort(strings, mid+1, to);
	Merge(strings, from, mid, to);
}
//Adapted from zybook
int _partition(token list[], int from,int to){
	//std::cout << "start partition ";
	//set to left pivot
	token pivot = list[from];
	
	//two iterators that goes "towards the middle" or until 
	int i = from - 1;
	int j = to + 1;
	
	
	while(i < j){
		i++; 
		//while(list[i] < pivot) {i++;}
		while(list[i].lowerCaseWord < pivot.lowerCaseWord) {i++;}
		j--; 
		//while(list[j] > pivot) {j--;}
		while(list[j].lowerCaseWord  > pivot.lowerCaseWord) {j--;}
		if(i < j) {	
			swap(list[i], list[j]);

		}
		//std::cout << i << " " << j << std::endl;
		//std::cout.flush();
	}
	return j;
	
}
//o(nlogn)
//Adapted from zybook
void SortingAlgorithms::QuickSort(token strlist[], int from, int to){
	if(from >= to) return;
		//std::cout << from << " " << to << std::endl;
		int p = _partition(strlist, from, to);
		//std::cout << "p: " << p << std::endl;
		QuickSort(strlist,from,p);
		QuickSort(strlist,p+1,to);
	
}


void SortingAlgorithms::CopyString(token from[], token to[] , int sizes){
	for(int i = 0; i < sizes; i++){
		to[i] = from[i];
	}
}
