#include "Algorithms.h"

void swap(std::string& a, std::string& b){
	std::string c;
	
	c = a;
	a = b;
	b = c;
}
int min_position(std::string[] array, int from, to){
	int min = 0;
	for(int i = from; i < to; i++){
		if(array[i] < array[min]){
			min = i;
		}
	
	}
	return min;
}
//helper function to find the lower alphabetical word
//returns true if less
bool AlphabetValue(std::string& a, std::string& b){
	
	//if i preemtively set it to a.size() i won't 
	//have to do an else statement saves a tiny bit of time
	int sizeLimit = a.size();
	if(sizeLimit > b.size()){
		sizeLimit = b.size();
	}
	
	for(int i = 0; i< sizeLimit; i++){
		//capitalize all of them so 97 - 122 (a-z) 65-90(A-Z)
		char letterA, letterB;
		//checks if the letter is a lower case or not and then subtracts 32
		if(a[i] > 96 && a[i] < 123) letterA = a[i] - 32;
		if(b[i] > 96 && b[i] < 123) letterB = b[i] - 32;
		
		//checks their ascii values to compare
		if(letterA > letterB){
			return false;
		}else if(letterB > letterA){
			return true;
		}
		//what happens if they are equal?
		//they keep going through the loop
		//dangerous if the word has "!" "?" or any punctuation marks.
		//Parser should remove these.
	}
	
	//if the two are completely identical, return A
	return true;
	
}
//o(n^2)
static void Algorithms::BubbleSort(std::string[] array, int size){
	//nested loop since bubble sort is basically 
	//"for every i, check j"
	for(int i = 0; i < size; i++){
		//incase the array is already sorted
		//we assume that it is true
		//and when a swap happens, it switches to negative and breaks
		bool isSorted = true;
		for(int j = 1; j < size - i; j++){
			//if the previous string is 
			if(AlphabetValue(array[j], array[j-1]) {
				swap(array[j], array[j-1]);
				isSorted = false;
			}
			
			if(!isSorted) break;
		}
	}
}
//o(n^2)
static void Algorithms::InsertionSort(std::string[] array, int size){
	
}
//o(n^2)
static void Algorithms::SelectionSort(std::string[] array, int size){
	
}
//o(nlogn)
static void Algorithms::MergeSort(std::string[] array, int from, int to){
	if(from == to) return;
	
}
//o(nlogn)
static void Algorithms::QuickSort(std::string[] array, int size){
	
}