#include "parser.h"

void testRemoveSpaces();
void testExpressionsToTokens();
void testShuntingYard();

int main()
{
    std::cout << std::endl;
    testRemoveSpaces();
    std::cout << std::endl;
    testExpressionsToTokens();
    std::cout << std::endl;
    testShuntingYard();
}

void testRemoveSpaces()
{
    std::string s = "This string      should   have   no spaces or tabs.";
    removeSpaces(s);
    std::cout << s << std::endl;
}

void testExpressionsToTokens()
{
    std::deque<Token> tokens = expressToTokens("1 + (     3\t^    7)");

    for (Token t : tokens) {
        std::cout << t.str;
    }
    std::cout << std::endl;
}

void testShuntingYard()
{
    const std::vector<std::string> expressions = {
          "3+4*2/(1-5)^2^3" // Wikipedia's example
        , "(2*3+3*4)"       // https://en.wikipedia.org/wiki/Shunting-yard_algorithm
        , "20-30/3+4*2^3"   //


        , "45 + 67*(4-5^2)"
        , "((3^2)^2)^2"
        , "14 /  7"
    };

    for (const auto& exp : expressions) {
        float result = doCalculation(exp);
        std::cout << "   result = " << result << std::endl << std::endl;
    }
}