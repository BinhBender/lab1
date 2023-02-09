#include "Timer.h"

//constructor doesn't need to do anything special
Timer::Timer(){

}
	
//sets the to n so that it could be used as the starting number
void Timer::StartTime(){
	start = std::chrono::high_resolution_clock::now();
}

//returns the duration of the since the last StartTime() function of the same Timer object
float Timer::EndTime(){
	float seconds = std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - start).count();
	return seconds;
}
