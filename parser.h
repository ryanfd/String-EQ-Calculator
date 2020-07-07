#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using std::string;
using std::stack;
using std::vector;

// for shunting-yard algorithm
using Token = string; // to specify specifics tokens from whole strings
using Operator_Name = string;
using Precedence    = int;
enum class Associates { none, left_to_right, right_to_left };
struct Operator { Precedence precedence; Associates associativity; };

// eliminate unneeded spacing and tabs
string removeSpaces(const string&);

// parse string into mathematical equation
float shuntingYard(const string&);

//
// helper methods
//

// bool isOpenParen(const Token& t) { return t == "("; }
// bool isClosedParen(const Token& t) { return t == ")"; }
// bool isParen(const Token& t) { return isOpenParen(t) || isClosedParen(t); }

// turn single char into string
string toString(char c)
{
    string str = "";
    str += c;
    return str;
}