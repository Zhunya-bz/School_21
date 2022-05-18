def readNumbers():
	f = open('numbers.txt')
	numString = f.read().rstrip() # убирает пробелы и симолы в конце строки
	numList = numString.split(",");
	for x in numList:
		print(x)
	f.close()	



if __name__ == '__main__':
	readNumbers()