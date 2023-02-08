#pragma once
#include <chrono>

class Timer{
//creates two variables to determine the change in time
private:
	std::chrono::time_point<std::chrono::system_clock> start, end;
public:
	//constructor doesn't need to do anything special
	Timer();
	
	//since the program is in a linear path, it should go start(), then end() with the end going after the sort
	void StartTime();
	std::chrono::duration<float> duration(); 
	
}
