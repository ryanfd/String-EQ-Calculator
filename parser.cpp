#include "parser.h"


void removeSpaces(string& str)
{
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}