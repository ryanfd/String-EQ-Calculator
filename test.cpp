#include <iostream>

#include "parser.h"

using std::cout;
using std::endl;

void testSpacing();

int main()
{
    testSpacing();
}

void testSpacing()
{
    string str = removeSpaces("T   his is a TEst   8973        425 87");
    cout << str << endl;
    string str1 = removeSpaces("T   his is+- /  % *87");
    cout << str1 << endl;
}