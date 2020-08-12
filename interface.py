import parser # swig - foreign function interface communication

goAgain = "y"

print("\n\n***STRING EQUALITY CALCULATOR***\n")

while (goAgain == "y") :
    print("Welcome to the Polyglot Interface!\n")

    print("VALID OPERATORS: { '^', '*', '/', '+', '-' }\n")

    # get equation
    print("***PLEASE ENTER WHOLE NUMBERS AND DO NOT INPUT ANY SPACES OR TABS***")
    inputValue = str(input("Please enter an equation using the '^', '*', '/', '+', or '-' operators: "))
    print("\n\nYour equation is: ", inputValue, " with a type of ", type(inputValue))

    result = parser.doCalculation(inputValue)
    print("Your answer is = ", result)
    print("\n")

    # implement the Haskell functions
    if (result.is_integer()):
        print("\nWhich recursive Haskell functions whould you like to apply to your answer?\n")
        print("Your options include:") 
        print("1. 'hail' for Hailstone algorithm.")
        print("2. 'fib' for the Fibonacci algorithm.")
        print("3. 'div' to get a list of the divisors of your result.")
        print("4. 'primes' to get a list of the primes less or equal to the result.")
        print("5. 'fact' to get the factorial value of your answer.")
        print("6. 'none' to not apply any haskell functions.")
        recursiveChoice = input("\nUsing a number of keyword described above, please input your choice of recursive functions: ")

        if (recursiveChoice.lower() == "hail" or recursiveChoice == "1"):
            print("hailstone\n")
        elif (recursiveChoice.lower() == "fib" or recursiveChoice == "2"):
            print("fibonacci")
        elif (recursiveChoice.lower() == "div" or recursiveChoice == "3"):
            print("divisors")
        elif (recursiveChoice.lower() == "primes" or recursiveChoice == "4"):
            print("primes")
        elif (recursiveChoice.lower() == "fact" or recursiveChoice == "5"):
            print("factorial")
        else :
            print("nothing")
    else :
        print("Recursive Haskell functions can only be applied to whole numbers.\n")

    # Allow multiple uses...
    goAgain = input("Would you like to go again? Y/n?")

    if (goAgain.lower() != "y"): 
        break

print("\n\n***Thanks for using the String Equality Calculator!***\n\n")