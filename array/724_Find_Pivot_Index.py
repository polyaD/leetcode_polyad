#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
############################################################################
#Author:polya 
#Email:polyaluthor@gmail.com
#Last updated:2019.10.15
#Version: 1.0 first
#need do: unit test
#Purpose: 724_Find_Pivot_Index.py
#Main logic principle:
#
#
#Usage:
#     example: python 724_Find_Pivot_Index.py
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
############################################################################
class Solution:
	def __init__(self,arr):
		self.arr=arr
		#print(self.k)
	def pivotIndex(self):
		S=sum(self.arr)
		leftsum=0
		for i,x in enumerate(self.arr):
			if leftsum==(S-leftsum-x):
				return i
			leftsum +=x
		return -1
#
#
#Call steps for ends
############################################################################
def call_main_steps():
	args=get_args()
	start =datetime.datetime.now()
	#arr=[1,12,-5,-6,50,3,100,20,11]
	arr=[1,2,1,2,1,3]
#self test##################################
	ar=Solution(arr)
	ar_pivot=ar.pivotIndex()
	print("The index of pivot element of array: %s"%(ar_pivot))
	print("Hello polya,welcome to the programming world")
	end=datetime.datetime.now()
	#print("The programming running time : "+str(end-start))
	print('Running time: %s Seconds'%(end-start))
	print("The programming finished time : "+str(end))
#input from out############################
#unit test ################################ 
#
#main
############################################################################
if __name__=='__main__':
	call_main_steps()

