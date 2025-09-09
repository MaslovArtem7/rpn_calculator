#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cctype>

double evaluate_rpn(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;
    std::vector<std::string> tokens;
    
    // Разбиваем выражение на токены
    while (iss >> token) {
        tokens.push_back(token);
    }
    
    for (const auto& token : tokens) {
        // Если токен - число
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            try {
                double num = std::stod(token);
                stack.push(num);
            } catch (const std::exception& e) {
                throw std::invalid_argument("Invalid number: " + token);
            }
        }
        // Если токен - оператор
        else {
            if (stack.size() < 2) {
                throw std::invalid_argument("Not enough operands for operator: " + token);
            }
            
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            double result;
            
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        throw std::invalid_argument("Division by zero");
                    }
                    result = a / b;
                    break;
                default:
                    throw std::invalid_argument("Unknown operator: " + token);
            }
            
            stack.push(result);
        }
    }
    
    if (stack.size() != 1) {
        throw std::invalid_argument("Invalid expression: too many operands");
    }
    
    return stack.top();
}





