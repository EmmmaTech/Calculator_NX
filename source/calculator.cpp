#include "calculator.hpp"

int MathCalculator::Addition(int a, int b) {
        int answer{};
        answer = a + b;
        return answer;
}

int MathCalculator::Subtraction(int a, int b) {
    int answer{};
    answer = a - b;
    return answer;
}

int MathCalculator::Mutiplication(int a, int b) {
    int answer{};
    answer = a * b;
    return answer;
}

int MathCalculator::Division(int a, int b) {
    int answer{};
    answer = a / b;
    return answer;
}

int MathCalculator::CalculateInt (std::string Operator, int a, int b) {
    // Find out what operator the user is using, then solve
    if (Operator == "+" || Operator == "addition") return Addition(a, b);
    if (Operator == "-" || Operator == "subtraction") return Subtraction(a, b);
    if (Operator == "*" || Operator == "mutiplication") return Mutiplication(a, b);
    if (Operator == "/" || Operator == "division") return Division(a, b);

    // Returns the answer for another variable
    return 0;
}
