class Coin(object):
	def __init__(self):
		self.amount = 0


class Penny(Coin):
	def __init__(self):
		self.value = 0.01
		self.unit_weight = 2.500  # grams
		self.given_weight = 0
		self.per_wrapper = 50
		self.amount = 0

	def __str__(self):
		return "{} pennies".format(self.amount)


class Nickel(Coin):
	def __init__(self):
		self.value = 0.05
		self.unit_weight = 5.000  # grams
		self.given_weight = 0
		self.per_wrapper = 40
		self.amount = 0

	def __str__(self):
		return "{} nickels".format(self.amount)


class Dime(Coin):
	def __init__(self):
		self.value = 0.10
		self.unit_weight = 2.268  # grams
		self.given_weight = 0
		self.per_wrapper = 50
		self.amount = 0

	def __str__(self):
		return "{} dimes".format(self.amount)


class Quarter(Coin):
	def __init__(self):
		self.value = 0.25
		self.unit_weight = 5.670  # grams
		self.given_weight = 0
		self.per_wrapper = 50
		self.amount = 0

	def __str__(self):
		return "{} quarters".format(self.amount)