def my_var():
	number = 42
	string1 = "42"
	string2 = "quarante-deux"
	numFloat = 42.0
	boolean = True
	listed = [42]
	diction = {42: 42}
	tuples = (42,)
	sett = set()

	print(number, "has a type ", type(number))
	print(string1, "has a type ", type(string1))
	print(string2, "has a type ", type(string2))
	print(numFloat, "has a type ", type(numFloat))
	print(boolean, "has a type ", type(boolean))
	print(listed, "has a type ", type(listed))
	print(diction, "has a type ", type(diction))
	print(tuples, "has a type ", type(tuples))
	print(sett, "has a type ", type(sett))


if __name__ == '__main__':
	my_var()