#include "Timer.h"

//constructor doesn't need to do anything special
Timer::Timer(){
	start = 0;
	end = 0;
}
	
//sets the to n so that it could be used as the starting number
void Timer::StartTime(){
	start = std::chrono::high_resolution_clock::now();
}

//returns the duration of the since the last StartTime() function of the same Timer object
std::chrono::duration<float> Timer::duration(){
	return std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - start);
}
