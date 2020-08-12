import parser

goAgain = "y"

print("\n\n***STRING EQUALITY CALCULATOR***\n")

while (goAgain == "y") :
    print("Welcome to the Polyglot Interface!\n")

    print("VALID OPERATORS: { '^', '*', '/', '+', '-' }\n")

    # get equation
    print("PLEASE DO NOT INPUT ANY SPACES OR TABS")
    inputValue = str(input("Please enter an equation using the '^', '*', '/', '+', or '-' operators: "))
    print("\n\nYour equation is: ", inputValue, " with a type of ", type(inputValue))

    print("Your answer is = ", parser.doCalculation(inputValue))

    # Allow multiple uses...
    goAgain = input("Would you like to go again? Y/n?")

    if (goAgain.lower() != "y") : 
        break

print("\n\n***Thanks for using the String Equality Calculator!***\n\n")