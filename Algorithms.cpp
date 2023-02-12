#include "Algorithms.h"

void swap(std::string& a, std::string& b){
	std::string c;
	
	c = a;
	a = b;
	b = c;
}

//helper function to find the lower alphabetical word
//returns true if a is "less than" b
bool AlphabetValue(std::string& a, std::string& b){
	
	//if i preemtively set it to a.size() i won't 
	//have to do an else statement saves a tiny bit of time
	long unsigned int sizeLimit = a.size();
	if(sizeLimit > b.size()){
		sizeLimit = b.size();
	}
	
	for(long unsigned int i = 0; i< sizeLimit; i++){
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

int min_position(std::string array[],int from,int to){
	
	int min = 0;
	//goes through array to find the minimum
	for(int i = from; i < to; i++){
		//if array at index i < min, set min to index i
		if(AlphabetValue(array[i], array[min])){
			min = i;
		}
	
	}
	return min;
}

//o(n^2)
void SortingAlgorithms::BubbleSort(std::string array[], int size){
	
	//nested loop since bubble sort is basically 
	//"for every i, check j"
	for(int i = 0; i < size; i++){
		//incase the array is already sorted
		//we assume that it is true
		//and when a swap happens, it switches to negative and breaks
		bool isSorted = true;
		for(int j = 1; j < size - i; j++){
			//if the previous string is 
			if(AlphabetValue(array[j], array[j-1])) {
				swap(array[j], array[j-1]);
				isSorted = false;
			}
			
			if(isSorted) {break;}
		}
	}
}

//o(n^2)
void SortingAlgorithms::InsertionSort(std::string array[] , int size){
	for(int i = 1; i < size; i++){
		std::string next = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > next){
			array[j] = array[j - 1];
			j--;
		}
		array[j] = next;
	}	
}
//o(n^2)
void SortingAlgorithms::SelectionSort(std::string array[], int size){
	//the opposite of bubble
	//left to right
	for(int i = 0; i < size - 1; i++){
		int min = min_position(array, i, size);
		
		swap(array[i], array[min]);
		
	}
}

//Adapted from zybook
void Merge(std::string strs[], int from, int mid, int to){
	//create a new array in order to make it easier.
	int size = to - from + 1;
	std::string* tempStorage = new std::string[size];
	
	//loop through the new array with two "pointers" 
	//the pointers will start at from, and mid+1
	//pointers will compare with the values of each other
	//and the pointer that has the lower value will insert
	//that value into the new array and shift up once
	int ipointer = from;
	int jpointer = mid + 1;
	int j = 0;
	while(ipointer <= mid && jpointer <=to){
		
		//if ipointer is less than jpointer, add value from 
		//ipointer otherwise add from jpointer.
		
		if(AlphabetValue(strs[ipointer], strs[jpointer])){
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
void SortingAlgorithms::MergeSort(std::string strings[], int from, int to){
	if(from == to) return;
	int mid = (from + to) / 2;
	MergeSort(strings,from, mid);
	MergeSort(strings, mid+1, to);
	Merge(strings, from, mid, to);
}
//Adapted from zybook
int partition(std::string list[], int from,int to){
	
	//set to left pivot
	std::string pivot = list[from];
	//two iterators that goes towards the middle
	int leftIterator = from - 1;
	int rightIterator = to + 1;
	
	
	while(leftIterator < rightIterator){
		
		leftIterator++;
		while (AlphabetValue(list[leftIterator], pivot)) {
			leftIterator++;
		}
		rightIterator--;
		while(!AlphabetValue(list[rightIterator], pivot)) {
			rightIterator--;
		}
		if(leftIterator < rightIterator) {
			swap(list[leftIterator],list[rightIterator]);
		}
	}
	return rightIterator;
	
}
//o(nlogn)
//Adapted from zybook
void SortingAlgorithms::QuickSort(std::string array[], int from, int to){
	if(from >= to) {return;}
	int p = partition(array, from, to);
	QuickSort(array,from,p);
	QuickSort(array,p+1,to);
		
}


void SortingAlgorithms::CopyString(std::string from[], std::string to[] , int sizes){
	for(int i = 0; i < sizes; i++){
		to[i] = from[i];
	}
}
