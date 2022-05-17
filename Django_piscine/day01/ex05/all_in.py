import sys

def findCity(state):
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
	newState = dict((k.lower(), v.lower()) for k,v in states.items())
	newCity = dict((k.lower(), v.lower()) for k,v in capital_cities.items())

	for x in states.keys():
		if (state.lower() and state.lower() in x.lower()):
			print(state.lower().title() + " is the state of " + newCity[newState.get(state.lower())].title())
			return (1)
	return (0)	

def findState(city):
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
	for x in capital_cities.values():
		if (city.lower() in x.lower()):
			for i in capital_cities.items():
				if i[1].lower() == city.lower():
					for state in states.items():
						if (state[1] == i[0]):
							print(city.lower().title() + " is the capital of " + state[0])
							return (1)
	return (0)


def find():
	if (len(sys.argv) == 2):
		listed = sys.argv[1].split(",")
		for x in listed:
			if (x.strip() and findCity(x.strip()) == 0 and findState(x.strip()) == 0):
				print(x.strip() + " is neither a capital city nor a state")

if __name__ == '__main__':
	find()	