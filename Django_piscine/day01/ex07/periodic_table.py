import sys

def createTable():

	lineList = []
	with open('periodic_table.txt') as f:
		for line in f:
			lineList.append(line.strip().split(","))
			# print(lineList)
	# print(lineList)

	xmlcode = '' # empty string
	for name, number, small, molar, elec in lineList:
		xmlcode += '<h4>"%s"</h4> \
		<ul> \
		<li>No "%s"</li> \
		<li>"%s"</li> \
		<li>"%s"</li> \
		<li>"%s" electron</li> \
		<ul>  ' %(name, number, small, molar, elec)
		 #'<img src="%s" alt="%s"></img>\n'%(src,alt)
	print(xmlcode)

if __name__ == '__main__':
	createTable()	