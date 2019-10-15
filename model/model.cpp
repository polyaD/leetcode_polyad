/*############################################################################
#Author:polya 
#Emalil:polyaluthor@gmail.com
#model.cpp
#Last updated:2019.time
#history version
#Version: 0.1
#Purpose:
#Main logic principle:
#Usage:
#     example: model.cpp
g++ model.cpp -o model -std=gnu++11
make model
./model
############################################################################*/
//logic outline:print information
//include input and out library
//logic struture:
//
#include <iostream>
//#include<time.h>
#include <ctime>
using namespace std;
//define class for solution
class Solution {
public:
};
//call main function
int main(int argc, char* argv[])
{
//self test ###################################################################
	clock_t begin = clock();
//run programming
	cout<<"Hello polya,welcome to the programming world" <<endl;
	clock_t end = clock();
	double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout<<"The programming had finished at time : "<< dt << "==============================" <<endl;
	cout <<"The programming running time: "<< elapsed_secs << " s" << endl;
//out test ####################################################################
//unit test ###################################################################
	return 0;
}
