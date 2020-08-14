# String EQ Calculator

The String Equality Calculator has a primary interface in python. It accepts a simple string as input. That string must be some kind of mathematical equation like ((3*2)^4)/(7+(15-8)). 

That string is passed to the C++ program which uses the Shunting-Yard Algorithm. This algorithm takes a string and the above characters on a stack and in a queue. Once this string has been parsed, it will calculate the above string. Then the result is returned.

Once the result is found, some recursive Haskell functions will be applied to the calculated value. The value is passed to a simple C interface, which then passes the value to Haskell by utilizing Haskell's 'foreign export' functionality.