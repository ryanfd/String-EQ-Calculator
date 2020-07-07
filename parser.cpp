#include "parser.h"

std::unordered_map <Operator_Name, Operator>  Operators =
{
  { "^", { 4, Associates::right_to_left } },
  { "*", { 3, Associates::left_to_right } },
  { "/", { 3, Associates::left_to_right } },
  { "+", { 2, Associates::left_to_right } },
  { "-", { 2, Associates::left_to_right } },
};

string convertStr(char c)
{
    string str = "";
    str += c;
    return str;
}

string removeSpaces(const string& str)
{
    string result = "";

    for (int i=0; i<str.length(); i++) {
        if (str[i] != ' ' || str[i] == '\t') result += tolower(str[i]); // make lowercase
    }

    return result;
}

float shuntingYard(const string& str)
{
    vector<Token> output;
    stack<Token> stack;

    int pos = 0;
    char currToken;
    while (pos < str.length()) {
        currToken = str[pos];

        if (isdigit(currToken)) { // token is a number
            output.push_back(convertStr(currToken));
        }

        pos++; // next char
    }
}