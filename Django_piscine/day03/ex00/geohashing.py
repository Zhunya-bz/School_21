import sys
import antigravity

def createLocation():
	if (len(sys.argv) != 4):
		print("Wrong argument!")
		sys.exit()
	antigravity.geohash(float(sys.argv[1]), float(sys.argv[2]), sys.argv[3].encode())

if __name__ == '__main__':
	createLocation()