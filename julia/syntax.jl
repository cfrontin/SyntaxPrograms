# Julia syntax program: a compact, runnable language refresher.

# This prints text output to terminal.
println("Hello, Julia syntax program!\n")

# FUNDAMENTAL TYPES
boolean_value = false            # Bool stores true/false.
integer_value = 2                # Int stores machine-sized signed integers.
float_value = 0.25               # Float64 is default floating-point type.
char_value = 'a'                 # Char stores one Unicode character.
text_value = "hello"             # String stores text data.
nothing_value = nothing          # nothing is Julia's "no value" singleton.

println(
    "bool=$(boolean_value), int=$(integer_value), float=$(float_value), " *
    "char=$(char_value), text=$(text_value), nothing=$(nothing_value)\n",
)

# COLLECTIONS
vector_value = [1, 2, 3]         # Vector is a one-dimensional dynamic array.
push!(vector_value, 4)           # push! mutates by appending one element.
tuple_value = (1, 2, 3)          # Tuple is fixed-size and immutable.
set_value = Set([1, 1, 2, 3])    # Set stores unique values.
dict_value = Dict("alice" => 10, "bob" => 7)  # Dict stores key/value pairs.
dict_value["carol"] = 9          # Add or update a dictionary entry.

println("vector=$(vector_value), tuple=$(tuple_value), set=$(set_value), dict=$(dict_value)\n")

# CONTROL FLOW
should_do = true
otherwise_todo = true
if !should_do
    println("First branch")
elseif otherwise_todo
    println("Else-if branch")
else
    println("Final else branch")
end

print("for loop: ")
for value in vector_value         # for iterates over iterable values.
    print("$(value) ")
end
println()

counter = 2
print("while loop: ")
while counter < 100               # while loops while condition remains true.
    global counter *= 2
    print("$(counter) ")
end
println("\n")

# FUNCTIONS
truncate_float(x::Float64)::Int = trunc(Int, x)  # Truncate without requiring exact integer.
square = x -> x * x                       # Anonymous function ("lambda").
println("truncate_float(3.14)=$(truncate_float(3.14)), square(3)=$(square(3))\n")

# STRUCTS (COMPOSITE TYPES)
mutable struct AClass
    x::Int
    z::Float64
end

function set_x!(obj::AClass, x_in::Int)
    obj.x = x_in
end

function set_z_as_product!(obj::AClass, c::Float64)
    obj.z = c * obj.x
end

obj = AClass(0, 0.0)
set_x!(obj, 4)
set_z_as_product!(obj, 5.2)
println("AClass z=$(obj.z)\n")

# EXCEPTIONS
try
    error("Example exception")    # error throws an exception.
catch exc
    println("Caught exception: $(exc)\n")
end

# COMPREHENSION
squares = [n^2 for n in 0:4]      # Comprehension builds array from expression.
println("squares=$(squares)")
