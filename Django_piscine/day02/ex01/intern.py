#!/usr/bin/python3

class Intern:
	# Name = "My name? I’m nobody, an intern, I have no name."

	def __init__(self, Name="My name? I’m nobody, an intern, I have no name."):
		self.Name = Name
		
	def __str__(self):
		return self.Name	

	class Coffee:
		def __str__(self):
			return "This is the worst coffee you ever tasted."	

	def work(self):
		raise Exception("I’m just an intern, I can’t do that...")

	def make_coffee(self):
		return Intern.Coffee()

def test():
	a = Intern()
	b = Intern("Mark")

	print(a)
	print(b)

	print(a.Coffee())

	try:
		a.work()
	except Exception as ex:
		print(ex)

	print(b.make_coffee())

if __name__ == '__main__':
	test()
