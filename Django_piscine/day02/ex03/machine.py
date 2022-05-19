#!/usr/bin/python3
import random
from beverages import HotBeverage, Coffee, Tea, Cappuccino, Chocolate

class CoffeeMachine:
	def __init__(self):
		self.brokenCount = 10
		
	class EmptyCup(HotBeverage):
		def __init__(self):
			self.price = 0.90
			self.name = "empty cup"	
		def description(self):
			return "An empty cup?! Gimme my money back!"

	class BrokenMachineException(Exception):
		def __init__(self):
			super().__init__("This coffee machine has to be repaired.")

	def repair(self):
		self.brokenCount = 10

	def serve(self):
		# print(self.brokenCount)
		if (self.brokenCount <= 0):
			raise CoffeeMachine.BrokenMachineException
		self.brokenCount -= 1
		drinks = [Coffee(), Tea(), Cappuccino(), Chocolate(), self.EmptyCup()]
		return random.choice(drinks)


		


def test():
	a = CoffeeMachine()
	print(a.BrokenMachineException())

	i = 0
	while (i < 21):
		try:
			print(a.serve())
			print(a.brokenCount)
			i += 1
		except Exception as ex:
			print(ex)	
			a.repair()


if __name__ == '__main__':
	test()	