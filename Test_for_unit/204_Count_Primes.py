#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
############################################################################
#Author:polya 
#Email:polyaluthor@gmail.com
#Last updated:2019.10.22
#Version: 1.0 first
#need do: unit test
#Purpose: 204_Count_Primes.py
#Main logic principle:
#
#
#Usage:
#     example: python 204_Count_Primes.py
############################################################################
"""
import os
import sys
import math
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
	def __init__(self,num):
		self.nums=num
		#print(self.k)
	def displayShow(self):
		#for i_iter in self.digits:
		#	print(i_iter)
		print("the input of number: "+str(self.nums))
	def countPrimes(self):
		if self.nums<=2:
			return 0
		prime=[1]*self.nums
		prime[0]=prime[1]=0
		for i in range(2,(int)(math.sqrt(self.nums)+1)):
			if prime[i]:
				for j in range(i+i,self.nums,i):
					prime[j]=0;
		#return  prime.count(1)
		count=0
		for i in range(0,len(prime)):
			if prime[i]:
				print(count)
			count=count+1
		return  prime.count(1)
#
#Call steps for ends
############################################################################
def call_main_steps():
	args=get_args()
	start =datetime.datetime.now()
	#arr=[1,12,-5,-6,50,3,100,20,11]
	#arr=[9,2,1,2,1,9]
	arr=[1,1,3,5,6,6,6.7]
	num=80
#self test##################################
	lena=Solution(num)
	ar_len=lena.displayShow()
	ar_len=lena.countPrimes()
	print("The count of prime of the number  : %s"%(ar_len))
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

