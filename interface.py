import ctypes

# c++ methods
parser = ctypes.CDLL('./parser.so')
parser.doCalculation.argtypes = [ctypes.c_wchar_p]
parser.doCalculation.restype = ctypes.c_float


# def ctypes_removeSpaces(a):
#     return parser.removeSpaces(ctypes.c_wchar_p(a))

def ctypes_doCalculation(a):
    return parser.doCalculation(ctypes.c_wchar_p(a))



# libfoo = ctypes.CDLL('libfoo.so')

# libfoo.Foo_new.argtypes = [ctypes.c_int]
# libfoo.Foo_new.restype = ctypes.c_void_p

# libfoo.Foo_bar.argtypes = [ctypes.c_void_p]
# libfoo.Foo_bar.restype = ctypes.c_int

# class Foo:
#     def __init__(self, bar):
#         self.foo = libfoo.Foo_new(bar)

#     def bar(self):
#         return libfoo.Foo_bar(self.foo)

# import parser



print("\n\n***STRING EQUALITY CALCULATOR***\n")

print("Welcome to the Polyglot Interface!\n")

print("VALID OPERATORS: { '^', '*', '/', '+', '-' }\n")

# get equation
inputValue = str(input("Please enter an equation using the '^', '*', '/', '+', or '-' operators:\n"))
print("Your equation is: ", inputValue, " with a type of ", type(inputValue))
# print("answer: ", ctypes_doCalculation(inputValue))
# result = ctypes_doCalculation(inputValue)
# parser.removeSpaces(inputValue)