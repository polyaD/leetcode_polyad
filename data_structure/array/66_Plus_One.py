#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
############################################################################
#Author:polya 
#Email:polyaluthor@gmail.com
#Last updated:2019.10.15
#Version: 1.0 first
#need do: unit test
#Purpose: 66_Plus_One.py
#Main logic principle:
#
#
#Usage:
#     example: python 66_Plus_One.py
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
		self.digits=arr
		#print(self.k)
	def displayShow(self):
		#for i_iter in self.digits:
		#	print(i_iter)
		print(self.digits)
	def plusOne(self):
		for i in range(len(self.digits)-1,-1,-1):
			print(self.digits[i])
			#if sum <10 each,no need carry
			if self.digits[i]<9:
				self.digits[i]+=1
				return self.digits
			#max:1+9=10,only 0
			else:
				self.digits[i]=0
		#why?
		#return 1
		return [1]+self.digits
#
#
#Call steps for ends
############################################################################
def call_main_steps():
	args=get_args()
	start =datetime.datetime.now()
	#arr=[1,12,-5,-6,50,3,100,20,11]
	#arr=[9,2,1,2,1,9]
	arr=[9,9,9]
#self test##################################
	ar=Solution(arr)
	ar_plusOne=ar.displayShow()
	ar_plusOne=ar.plusOne()
	print("The element of plusOne  array: %s"%(ar_plusOne))
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

