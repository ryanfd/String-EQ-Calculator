#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

class Token {
public:
    enum class Type { // one token is a character in the given string
        Unknown,
        Number, 
        Operator, 
        LeftParen,
        RightParen,
    };

    // fields
    const Type type;
    const std::string str;
    const int precedence;
    const bool rightAssociative;

    // constructor
    Token(Type t, const std::string& s, int prec = -1, bool ra = false)
    : type{t}, str(s), precedence(prec), rightAssociative{ra}
    { }
};

// doublen ended queue to store numbers and operators
std::deque<Token> expressToTokens(const std::string& s);

// implement calculation from deque
std::deque<Token> shutingYard(const std::deque<Token>& tokens);

// do the calculations
float doCalculation(const std::string& str);

// clear empty spaces and tabs from string
void removeSpaces(std::string& str);