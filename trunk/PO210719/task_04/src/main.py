class Item:
    def __init__(self, item_id, cost, weight, durability, age):
        self.id = item_id
        self.cost = cost
        self.weight = weight
        self.durability = durability
        self.age = age

    def calculate_cost_per_gram(self):
        return self.cost / self.weight

    def remaining_lifetime(self):
        return self.durability - self.age

    def display(self):
        print("Item ID:", self.id)
        print("Cost:", self.cost)
        print("Weight:", self.weight)
        print("Durability:", self.durability)
        print("Age:", self.age)


item1 = Item(1, 10, 100, 50, 20)
item2 = Item(2, 20, 150, 75, 30)
item3 = Item(3, 15, 120, 60, 40)


item1.display()
print("Cost per gram:", item1.calculate_cost_per_gram())
print("Remaining lifetime:", item1.remaining_lifetime())
print()

item2.display()
print("Cost per gram:", item2.calculate_cost_per_gram())
print("Remaining lifetime:", item2.remaining_lifetime())
print()

item3.display()
print("Cost per gram:", item3.calculate_cost_per_gram())
print("Remaining lifetime:", item3.remaining_lifetime())