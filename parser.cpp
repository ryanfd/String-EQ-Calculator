#include "parser.h"

std::ostream& operator<<(std::ostream& out, const Token& token) // output tokens
{
    out << token.str;
    return out;
}


std::deque<Token> expressToTokens(const std::string& str)
{
    std::deque<Token> tokens;

    // remove spaces from string
    std::string newStr = str;
    removeSpaces(newStr);

    for (const auto* p = newStr.c_str(); *p; p++) {
        if (isdigit(*p)) {
            const auto* b = p;

            while (isdigit(*p)) {
                p++;
            }

            // add number to back of deque
            const auto s = std::string(b, p);
            tokens.push_back(Token{Token::Type::Number, s});
            p--;
        } else {
            Token::Type t = Token::Type::Unknown;
            int prec = -1;
            bool ra = false;
            switch(*p) {
                default:
                    break;
                
                case '(':
                    t = Token::Type::LeftParen;
                break;

                case ')':
                    t = Token::Type::RightParen;
                    break;

                case '^':
                    t = Token::Type::Operator;
                    prec = 4;
                    ra = true;
                    break;

                case '*':
                    t = Token::Type::Operator;
                    prec = 3;
                    break;

                case '/':
                    t = Token::Type::Operator;
                    prec = 3;
                    break;

                case '+':
                    t = Token::Type::Operator;
                    prec = 2;
                    break;

                case '-':
                    t = Token::Type::Operator;
                    prec = 2;
                    break;
            }
            tokens.push_back(Token{t, std::string(1, *p), prec, ra});
        }
    }

    return tokens;
}

std::deque<Token> shutingYard(const std::deque<Token>& tokens) {
    std::vector<Token> stack;
    std::deque<Token> output;

    // while there are tokens to process
    for (auto t : tokens) {
        // read token
        switch(t.type) {
            case Token::Type::Number:
            {
                // if number, add to output queue
                output.push_back(t);
                break;
            }
            
            case Token::Type::Operator:
            {
                // if operator...
                const auto o1 = t;

                // while there are operators on the stack,
                while (!stack.empty()) {
                    const auto o2 = stack.back();

                    // either o1 is left-associative and its precedence is less or equal to that of o2,
                    // or if o2 is right associative, and has precedence, less than 02
                    if ((!o1.rightAssociative && o1.precedence <= o2.precedence) || 
                        (o1.rightAssociative && o1.precedence < o2.precedence)) {
                            stack.pop_back();
                            output.push_back(o2);

                            continue;
                    }
                    break;
                }
                stack.push_back(o1);
                break;
            }

            case Token::Type::LeftParen:
            {
                stack.push_back(t);
                break;
            }

            case Token::Type::RightParen:
            {
                bool foundParen = false;

                // until token at the top of the stack is a left a parenthesis
                while (!stack.empty() && stack.back().type != Token::Type::LeftParen) {
                    // pop operators off stack on output queue
                    output.push_back(stack.back());
                    stack.pop_back();
                    foundParen = true;
                }

                // put left parenthesis on stack, not queue
                stack.pop_back();

                if (!foundParen && stack.empty()) {
                    std::cout << "missing left parenthesis (" << t.str.c_str() << ")" << std::endl;
                    return {}; // empty dequeue
                }
                break;
            }

            default:
            {
                std::cout << "invalid token" << std::endl;
                return {};
                break;
            }
        }
    }

    while (!stack.empty()) {
        if (stack.back().type == Token::Type::LeftParen) {
            std::cout << "missing right parenthesis" << std::endl;
        }

        // pop operator onto output queue
        output.push_back(std::move(stack.back()));
        stack.pop_back();
    }
    return output;
}

// do the calculations
float doCalculation(const std::string& exp)
{
    const auto tokens = expressToTokens(exp);
    auto output = shutingYard(tokens);
    std::vector<float> stack;

    while (!output.empty()) {
        std::string op;
        const auto token = output.front();
        output.pop_front();

        switch(token.type) {
            case Token::Type::Number:
            {
                stack.push_back(std::stoi(token.str));
                op = "Push " + token.str;
                break;
            }
            
            case Token::Type::Operator:
            {
                const auto rhs = stack.back();
                stack.pop_back();
                const auto lhs = stack.back();
                stack.pop_back();

                switch(token.str[0]) { // do calculations
                    default:
                    {
                        std::cout << "error" << std::endl;
                        exit(0);
                        break;
                    }

                    case '^':
                    {
                        stack.push_back(static_cast<float>(pow(lhs, rhs)));
                        break;
                    }

                    case '*':
                    {
                        stack.push_back(lhs*rhs);
                        break;
                    }

                    case '/':
                    {
                        stack.push_back(lhs/rhs);
                        break;
                    }

                    case '+':
                    {
                        stack.push_back(lhs+rhs);
                        break;
                    }

                    case '-':
                    {
                        stack.push_back(lhs-rhs);
                        break;
                    }
                }
                op = "Push " + std::to_string(lhs) + " " + token.str + " " + std::to_string(rhs);
            }
            break;

            default:
            std::cout << "token error" << std::endl;
            exit(0);
        }
    }
    return stack.back();
}

void removeSpaces(std::string& str)
{
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}