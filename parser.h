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

using std::string;
using std::deque;
using std::vector;

using std::cout;
using std::endl;

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
    const string str;
    const int precedence;
    const bool rightAssociative;

    // constructor
    Token(Type t, const string& s, int prec = -1, bool ra = false)
    : type{t}, str(s), precedence(prec), rightAssociative{ra}
    { }
};

// doublen ended queue to store numbers and operators
deque<Token> expressToTokens(const string& s);

// implement calculation from deque
deque<Token> shutingYard(const deque<Token>& tokens);

// clear empty spaces and tabs from string
void removeSpaces(string& str);