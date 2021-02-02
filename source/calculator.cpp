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

int MathCalculator::CalculateMoreInt(std::string_view Operator) {
    int answer = VectorCalculator[0];
    VectorCalculator.erase(VectorCalculator.begin());

    while (!VectorCalculator.empty()) {
        switch (turnStringToIntOperator(Operator)) {
            case 1:
            answer += VectorCalculator[0];
            break;

            case 2:
            answer -= VectorCalculator[0];
            break;

            case 3:
            answer *= VectorCalculator[0];
            break;

            case 4:
            answer /= VectorCalculator[0];
            break;

            default:
            break;
        }

        VectorCalculator.erase(VectorCalculator.begin());
    }

    return answer;
}
