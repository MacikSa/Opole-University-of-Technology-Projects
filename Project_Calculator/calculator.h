#include <string>
#include <vector>

int getPrecedence(char op);
std::vector<std::string> infixToRPN(const std::string& expression);
double evaluateRPN(const std::vector<std::string>& rpn);
void runCalculator();