#!/usr/bin/env python3
"""Python syntax program: a compact, runnable language refresher."""

# This prints text to the terminal.
print("Hello, Python syntax program!\n")

# FUNDAMENTAL TYPES
boolean_value = False  # bool stores True/False.
integer_value = 2  # int stores whole numbers (arbitrary precision).
float_value = 0.25  # float stores double-precision decimals.
text_value = "hello"  # str stores Unicode text.
none_value = None  # None represents "no value".

# This formats and prints values with f-strings.
print(
    f"bool={boolean_value}, int={integer_value}, float={float_value}, "
    f"text={text_value}, none={none_value}\n"
)

# COLLECTIONS
list_value = [1, 2, 3]  # list is ordered and mutable.
tuple_value = (1, 2, 3)  # tuple is ordered and immutable.
set_value = {1, 2, 2, 3}  # set is unordered and unique.
dict_value = {"alice": 10, "bob": 7}  # dict maps keys to values.
dict_value["carol"] = 9  # Add/update a dictionary entry.
list_value.append(4)  # Append to a list in place.

print(f"list={list_value}, tuple={tuple_value}, set={set_value}, dict={dict_value}\n")

# CONTROL FLOW
should_do = True  # Condition for branch logic.
otherwise_todo = True  # Secondary condition.
if not should_do:
    print("First branch")
elif otherwise_todo:
    print("Else-if branch")
else:
    print("Final else branch")

print("for loop:", end=" ")
for value in list_value:  # Iterate directly over sequence values.
    print(value, end=" ")
print()

counter = 2  # Mutable loop state.
print("while loop:", end=" ")
while counter < 100:  # Loop while condition remains true.
    counter *= 2
    print(counter, end=" ")
print("\n")

# FUNCTIONS
def truncate_float(x: float) -> int:
    """Convert a float to int by truncating decimals."""
    return int(x)


square = lambda x: x * x  # Lambda creates a small anonymous function.
print(f"truncate_float(3.14)={truncate_float(3.14)}, square(3)={square(3)}\n")

# CLASSES
class AClass:
    """Demonstrates encapsulated instance state with methods."""

    def __init__(self) -> None:
        self.x = 0
        self.z = 0.0

    def set_x(self, x_in: int) -> None:
        self.x = x_in

    def set_z_as_product(self, c: float) -> None:
        self.z = c * self.x

    def get_z(self) -> float:
        return self.z


obj = AClass()
obj.set_x(4)
obj.set_z_as_product(5.2)
print(f"AClass z={obj.get_z()}\n")

# EXCEPTIONS
try:
    raise ValueError("Example exception")  # Raise a runtime exception.
except ValueError as exc:
    print(f"Caught exception: {exc}\n")

# COMPREHENSION
squares = [n * n for n in range(5)]  # Comprehension builds list from expression.
print(f"squares={squares}")
