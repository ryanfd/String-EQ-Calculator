import parser # swig - foreign function interface communication
from subprocess import call # use to run haskell/c programs as executable

goAgain = "y"

print("\n***STRING EQUALITY CALCULATOR***\n")

while (goAgain == "y") :
    print("\nWelcome to the Polyglot Interface!\n")

    print("VALID OPERATORS: { '(', ')', '^', '*', '/', '+', '-' }\n")

    # get equation
    print("***PLEASE ENTER WHOLE NUMBERS AND DO NOT INPUT ANY SPACES OR TABS***")
    inputValue = str(input("Please enter an equation using the '(', ')', '^', '*', '/', '+', or '-' operators: "))
    print("\n\nYour equation is: ", inputValue, " with a type of ", type(inputValue))

    result = parser.doCalculation(inputValue)
    print("Your answer is = ", result)
    print("\n")

    # implement the Haskell functions
    print("Using Hailstone, Fibonacci and Factorial Haskell functions, the following amounts were found:")
    # call C stub function file as an executable
    call(["./wrap", str(result)]) # pass 'result' as an argument to C stub function which passes 'result' to Haskell
    print("\n")

    # Allow multiple uses...
    goAgain = input("Would you like to go again? y/n? ")

    if (goAgain.lower() != "y"): 
        break

print("\n\n***Thanks for using the String Equality Calculator!***\n\n")