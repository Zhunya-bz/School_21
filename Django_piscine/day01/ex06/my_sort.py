def sortDict():
	d = {
		'Hendrix' : '1942',
		'Allman' : '1946',
		'King' : '1925',
		'Clapton' : '1945',
		'Johnson' : '1911',
		'Berry' : '1926',
		'Vaughan' : '1954',
		'Cooder' : '1947',
		'Page' : '1944',
		'Richards' : '1943',
		'Hammett' : '1962',
		'Cobain' : '1967',
		'Garcia' : '1942',
		'Beck' : '1944',
		'Santana' : '1947',
		'Ramone' : '1948',
		'White' : '1975',
		'Frusciante': '1970',
		'Thompson' : '1949',
		'Burton' : '1939',
	}

	sorted_values = sorted(d.values()) # Sort the values
	sorted_keys = sorted(d, key=d.get)  # [1, 3, 2]

	diction = {}

	for i in range(len(sorted_values)):
		if sorted_values[i] in diction:
			diction[sorted_values[i]] += [sorted_keys[i]]
		if sorted_values[i] not in diction:
			diction[sorted_values[i]] = []
			diction[sorted_values[i]] += [sorted_keys[i]]

	ex = []
	for i in diction.values():
		i.sort()
		ex += i
	for i in ex:
		print(i)
		

if __name__ == '__main__':
	sortDict()		