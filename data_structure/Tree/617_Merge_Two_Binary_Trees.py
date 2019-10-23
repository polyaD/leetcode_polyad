#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
############################################################################
#Author:polya 
#Email:polyaluthor@gmail.com
#Last updated:2019.10.22
#Version: 1.0 first
#need do: unit test
#Purpose: 617_Merge_Two_Binary_Trees.py
#Main logic principle:
#
#
#Usage:
#     example: python 617_Merge_Two_Binary_Trees.py
############################################################################
"""
import os
import sys
import datetime
import argparse
import pandas as pd
#
#
#Get Argv
#get ready parameters and out help inforamtion
#############################################################################
def get_args():
	parse=argparse.ArgumentParser(description='annot expression in one file')
	parse.add_argument('-u','--usage',help="usage: python $0  -in 1,2,3 ")
	parse.add_argument('-in','--in_list',type=str,help="input ready files ")
	parse.add_argument('-out','--out_file',type=str,help="set out name of files: eg.select.txt ")
	args=parse.parse_args()
	return vars(args)
############################################################################
#
#
#Do somthing for data
class TreeNode(object):
	def __init__(self,key=None,lchild=None,rchild=None):
		self.key=key
		self.lchild=lchild
		self.rchild=rchild
############################################################################
class Solution:
	def __init__(self,data_list):
		self.it=iter(data_list)
	def createBiTree(self,bt=None):
		try:
			next_data=next(self.it)
			if next_data is '#':
				bt=None
			else:
				bt=TreeNode(next_data)
				bt.lchild=self.createBiTree(bt.lchild)
				bt.rchild=self.createBiTree(bt.rchild)
		except Exception as e:
			print(e)
		return bt
		#print(self.k)
	def preOrderTrave(self,bt):
			if bt is not None:
				print(bt.key,end=" ")
				self.preOrderTrave(bt.lchild)
				self.preOrderTrave(bt.rchild)
	def printTrave(self,bt):
			print("\n先序遍历: ", end="")
			self.preOrderTrave(bt)
	def mergeTrees(self,t1,t2):
		if  t1==None and t2==None:
			return None
		elif t1==None:
			return t2
		elif t2==None:
			return t1
		else:
			t1.key+=t2.key
			t1.left=self.mergeTrees(t1.lchild,t2.lchild)
			t1.right=self.mergeTrees(t1.rchild,t2.rchild)
		return t1
#
#
#Call steps for ends
############################################################################
def call_main_steps():
	args=get_args()
	start =datetime.datetime.now()
	#arr=[1,12,-5,-6,50,3,100,20,11]
	#arr=[9,2,1,2,1,9]
	arr=[1,1,3,5,6,6,8]
	arr1=[1,1,3,5,6,6,7]
#self test##################################
	#data = input("Please input the node value: ")
	data_list = list(arr1)
	btree = Solution(data_list)
	btree1=Solution(arr)
	root=btree.createBiTree()
	root1=btree1.createBiTree()
	btree.printTrave(root)
	btree.printTrave(root1)
	btr = Solution(data_list)
	rootMe=btr.mergeTrees(root,root1)
	print("\ntype of rootMe\n"+str(type(rootMe)))
	btree.printTrave(rootMe)
	print("\n\n============================================================")
	print("Hello polya,welcome to the programming world")
	end=datetime.datetime.now()
	#print("The programming running time : "+str(end-start))
	print('The programming running time: %s Seconds'%(end-start))
	print("The programming finished time : "+str(end))
	print("============================================================")
#input from out############################
#unit test ################################ 
#
#main
############################################################################
if __name__=='__main__':
	call_main_steps()

