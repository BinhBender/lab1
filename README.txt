This program requires the stdlib 6 for c & c++
use 
sudo apt-get install stdlibc++6
sudo apt-get install stdlibc6

Don't compile all files
Exclude test.cpp if its in zip
g++ BNmain.cpp BNAlgorithms.cpp BNAlgoTest.cpp BNTimer.cpp BNTextParser.cpp -o main.out
