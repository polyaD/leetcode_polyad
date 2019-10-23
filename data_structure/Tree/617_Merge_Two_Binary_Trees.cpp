/*############################################################################
#Author:polya 
#Emalil:polyaluthor@gmail.com
#617_Merge_Two_Binary_Trees.cpp
#Last updated:2019.10.23
#history version
#Version: 0.1
#Purpose:
#Main logic principle:
#Usage:
#     example: model.cpp
g++ model.cpp -o model -std=gnu++11
make model
./model
g++ 617_Merge_Two_Binary_Trees.cpp -o 617 -std=gnu++11
make 617
./617
############################################################################*/
//logic outline:print information
//include input and out library
//logic struture:
//
#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "stdio.h"
using namespace std;
//define a binary tree node
struct TreeNode{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//define class for solution
class Solution {
	public:
		TreeNode* mergeTrees(TreeNode* t1,TreeNode* t2){
			if(!t1){
				return t2;
			}
			else if(!t2){
				return t1;
			}else{
				TreeNode* node = new TreeNode(t1->val + t2->val);
				node->left = mergeTrees(t1->left, t2->left);
				node->right = mergeTrees(t1->right, t2->right);
			return node;
			}
		}
// travel binary tree
// flag==0 preOrder  flag=1 inOrder flag=2 postOrder
	void displayInfo_Order(TreeNode* t,vector<int> &result,int flag){
	if(flag==0){
		if(t!=NULL){
			result.push_back(t->val);
			displayInfo_Order(t->left,result,0);
			displayInfo_Order(t->right,result,0);
		}
	}else if(flag==1){
		if(t!=NULL){
			displayInfo_Order(t->left,result,1);
			result.push_back(t->val);
			displayInfo_Order(t->right,result,1);
		}
	}else{
		if(t!=NULL){
			displayInfo_Order(t->left,result,2);
			displayInfo_Order(t->right,result,2);
			result.push_back(t->val);
		}
	}
	}
	//travel BT
	void traverse(vector<int> nums){
		vector<int>::size_type size = nums.size();
		for (size_t i = 0; i < size; i++){
			cout << nums[i] << ' ';
		}
		cout << endl;
	}
	//init BT
	TreeNode* initBTree(int elements[], int size){
		if (size < 1){
			return NULL;
		}
		TreeNode **nodes = new TreeNode*[size];
		for (int i = 0; i < size; i++){
		/*/v1
			if (elements[i] == 0){
				nodes[i] = NULL;
			}else{
				nodes[i] = new TreeNode(elements[i]);
			}
		*/
			nodes[i] = new TreeNode(elements[i]);
		}
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(nodes[0]);
		TreeNode *node;
		int index = 1;
		while (index < size){
			node = nodeQueue.front();
			nodeQueue.pop();
			nodeQueue.push(nodes[index++]);
			node->left = nodeQueue.back();
			nodeQueue.push(nodes[index++]);
			node->right = nodeQueue.back();
		}
		return nodes[0];
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
	int nums[] = { 1, 2, 3, 0, 1, 5, 6, 10, 7 };
	int nums_2[] = { 1, 2, 3, 4, 9, 5, 6, 10, 7 };
	Solution bT;
	//init BTree
	TreeNode *bt = bT.initBTree(nums, 9);
	TreeNode *bt2 = bT.initBTree(nums_2, 9);
	//display
	vector<int> preResult;
	bT.displayInfo_Order(bt,preResult,1);
	bT.traverse(preResult);
	preResult.clear();
	bT.displayInfo_Order(bt2,preResult,1);
	bT.traverse(preResult);
	//merge
	vector<int> mergeResult;
	TreeNode *btM=bT.mergeTrees(bt,bt2);
	bT.displayInfo_Order(btM,mergeResult,1);
	bT.traverse(mergeResult);
	cout<<" The out One "<<endl;
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
