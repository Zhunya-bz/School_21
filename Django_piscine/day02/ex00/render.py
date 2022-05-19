#!/usr/bin/python3

import sys
import os
import re

def createHTML():
	if (len(sys.argv) != 2):
		print("Error argument!")
		sys.exit()

	try:
		file = open(sys.argv[1], 'r+')
	except OSError:
		print("Could not open/read file:", sys.argv[1])
		sys.exit()

	try:
		fileSett = open("./settings.py", 'r')
	except OSError:
		print("Could not open/read file:", "settings.py")
		sys.exit()

	lineList = []
	diction = {}
	for line in fileSett:
		list1 = line.strip().split("=")
		for i in range(len(list1)):
			list1[i] = list1[i].replace("\"", '').strip()
		diction[list1[0]] = list1[1]	
		lineList.append(list1)

	resString = file.read().strip() # убирает пробелы и симолы
	t = resString.format(title = diction["title"], name = diction["name"], surname = diction["surname"], age = diction["age"], prof = diction["prof"])
	fileWrite = open(sys.argv[1][:sys.argv[1].find(".")] + ".html", "w")
	fileWrite.write(t)
	fileWrite.close()
	file.close()
	fileSett.close()


if __name__ == '__main__':
	createHTML()
