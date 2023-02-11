#pragma once
#include <chrono>

class Timer{
//creates two variables to determine the change in time
private:
	std::chrono::high_resolution_clock::time_point start, end;
public:
	//constructor doesn't need to do anything 
	Timer();
	
	//since the program is in a linear path, it should go start(), then end() with the end going after the sort
	void StartTime();
	double EndTime(); 
	
};
