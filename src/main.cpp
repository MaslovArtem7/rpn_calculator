#include <iostream>
#include <string>
#include <stdexcept>
#include "rpn.h"  // ОСТАВЬТЕ ТОЛЬКО ЭТОТ include для rpn.h

int main() {
    std::string expression;
    std::cout << "Enter RPN expression: ";  // Добавил двоеточие
    std::getline(std::cin, expression);

    try {
        double result = evaluate_rpn(expression);
        std::cout << "Result: " << result << std::endl;  // Исправил пробел

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;       
    }
    return 0;
}