import sys

def findState():
	states = {
		"Oregon" : "OR",
		"Alabama" : "AL",
		"New Jersey": "NJ",
		"Colorado" : "CO"
	}
	capital_cities = {
		"OR": "Salem",
		"AL": "Montgomery",
		"NJ": "Trenton",
		"CO": "Denver"
	}
	if (len(sys.argv) == 2):
		if (sys.argv[1] in capital_cities.values()):
			for i in capital_cities.items():
				if i[1] == sys.argv[1]:
					for state in states.items():
						if (state[1] == i[0]):
							print(state[0])
		else:
			print("Unknown capital city")	


if __name__ == '__main__':
	findState()	