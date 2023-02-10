#pragma once
#include <chrono>

//Code from youtube.com/TheCherno
class Timer{
//creates two variables to determine the change in time
private:
	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration<double> duration_;
public:
	//constructor doesn't need to do anything 
	Timer();
	
	//since the program is in a linear path, it should go start(), then end() with the end going after the sort
	void StartTime();
	float EndTime(); 
	
};
