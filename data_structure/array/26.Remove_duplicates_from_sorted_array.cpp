/*############################################################################
#Author:polya 
#Emalil:polyaluthor@gmail.com
#26.Remove_duplicates_from_sorted_array.cpp
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
g++ 26.Remove_duplicates_from_sorted_array.cpp -o 26 -std=gnu++11
make 26
./26
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
using namespace std;
//define class for solution
class Solution {
	public:
		int removeDuplicates(vector<int>& nums){
			if(nums.size()==0) return 0;
			int i=0;
			for (int j=1;j<nums.size();j++){
				if (nums[j] != nums[i]) {
					i++;
					nums[i]=nums[j];
				}
			}
			return i+1;
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
	cout<<"//input element: " <<endl;
//run programming############################
	vector<int> arr;
//	vector<int> f_redu;
	int f_redu;
//arr={1,12,-5,-6,50,3};
	//arr={1,2,1,0,0,3,3,4};
	//arr={1,1,2};
	arr={0,0,1,1,2,3,3,4};
	//unsigned int k=4;
	Solution fRedu;
//	fRedu.displayInfo(arr);
	f_redu=fRedu.removeDuplicates(arr);
	cout<<" The out of ends:  "<<endl;
	fRedu.displayInfo(f_redu);
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
