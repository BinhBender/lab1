#include "Timer.h"

//constructor doesn't need to do anything special
Timer::Timer(){

}
	
//sets the to n so that it could be used as the starting number
void Timer::StartTime(){
	start = std::chrono::high_resolution_clock::now();
}

//returns the duration of the since the last StartTime() function of the same Timer object
double Timer::EndTime(){
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timespan = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	return timespan.count();
}
