import sys

def createTable():

	lineList = []
	with open('periodic_table.txt') as f:
		for line in f:
			lineList.append(line.strip().split("="))

	diction = {}
	subList = []
	for item in lineList:
		subSubList = []
		subList = item[1].strip().split(",")
		for li in subList:
			subSubList.append(li.strip().split(":"))
		diction[item[0].strip()] = subSubList

	# sorted(diction)
	# print(diction.items())
	# sorted_it = sorted(diction.items(), key=lambda item: item[1][0][1])
	# # print(sorted_it)
	# sorted_dict = {k: v for k, v in sorted_it}
	# print(sorted_dict)  # {1: 1, 3: 4, 2: 9}


	xmlcode = '''<!DOCTYPE html>
		<html lang="en">
		<head>
			<meta charset="UTF-8">
			<meta http-equiv="X-UA-Compatible" content="IE=edge">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<title>Day01_ex07</title>
		</head>
		<body>
		<table>	
		''' 
	for key in diction:
		xmlcode += f'''
		<tr>
			<td style="border: 1px solid black; padding:10px">
				<h4>{key}</h4> 
				<ul> 
					<li>No {diction[key][1][1]}</li> 
					<li>{diction[key][2][1]}</li> 
					<li>{diction[key][3][1]}</li> 
					<li>{diction[key][4][1]} electron</li> 
				</ul> 
			</td>
		</tr>
		 ''' 
	xmlcode += ''' 
	</table>
	</body>
	</html> '''	 
	file = open("periodic_table.html", "w")
	file.write(xmlcode)
	file.close()

if __name__ == '__main__':
	createTable()	