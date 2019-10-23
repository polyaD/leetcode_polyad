/*############################################################################
#Author:polya 
#Emalil:polyaluthor@gmail.com
#204_Count_Primes.cpp
#Last updated:2019.10.22
#history version
#Version: 0.1
#Purpose:
#Main logic principle:
#Usage:
#     example: model.cpp
g++ model.cpp -o model -std=gnu++11
make model
./model
g++ 204_Count_Primes.cpp -o 204 -std=gnu++11
make 204
./204
############################################################################*/
//logic outline:print information
//include input and out library
//logic struture:
//
#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "stdio.h"
using namespace std;
//define class for solution
class Solution {
	public:
		int countPrimes(int num){
			if(num<=2) return 0;
			vector<bool> prime(num,true);
			prime[0]=false,prime[1]=false;
			for(int i=0;i<=sqrt(num);++i){
				if(prime[i]){
					for(int j=i*i;j<num;j+=i){
						prime[j]=false;
					}
				}
			}
			int sizes=prime.size();
			int nu=0;
			for(int k=0;k<sizes;k++){
				//printf("%d ",nu);
				if(prime[k]==1){
					printf("%d ",nu);
				//	cout<<nu<<endl;
				}
				nu=nu+1;
				//cout<<prime[k]<<endl;
			}
			return count(prime.begin(), prime.end(), true);
			}
	void displayInfo(vector<int>& nums,bool flag){
		if(flag==1){
			for (int i =0;i<nums.size();i++){
				cout<<nums[i]<<endl;
			}
		}else{
			// Convert vector to string
			ostringstream vts;
			vector<int> vec=nums;
			if (!vec.empty()){
			copy(vec.begin(), vec.end()-1,ostream_iterator<int>(vts, ", ")); 
			vts << vec.back();
			}
			cout<<vts.str()<<endl;
		}
	}
	void displayInfo(int nums){
		cout<<nums<<endl;
	}
};
//call main function
int main(int argc, char* argv[])
{
//self test ###################################################################
	clock_t begin = clock();
	cout<<"Hello polya,welcome to the programming world" <<endl;
	cout<<"===========================================" <<endl;
	cout<<"//out element: " <<endl;
//run programming############################
	int fPrime;
//	vector<int> f_redu;
	int num;
//arr={1,12,-5,-6,50,3};
	//arr={1,2,1,0,0,3,3,4};
	//arr={1,1,2};
	//arr={0,0,1,1,2,3,3,4};
	num=80;
	//unsigned int k=4;
	Solution f_prime;
//	fRedu.displayInfo(arr);
	fPrime=f_prime.countPrimes(num);
	cout<<" The out of ends:  "<<fPrime<<endl;
	f_prime.displayInfo(fPrime);
	cout<<" The plus One "<<endl;
//###########################################
	cout<<"===========================================" <<endl;
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
