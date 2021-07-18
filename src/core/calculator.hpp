#pragma once

#include <stack>
#include <string>
#include <cmath>

#include "singleton.hpp"

/**
 * @brief A class that can solve mathematical expressions.
 * Base of the code is from here: https://www.codinghelmet.com/exercises/expression-evaluator
 * (Note that the code is orignally in C#, C++ implementation made by me (EmreTech))
 */
struct Calculator
{
    NON_MOVABLE(Calculator)
    NON_COPYABLE(Calculator)

    static Calculator &getInstance();

    double evaluateExpression(std::string &exp);

    private:
    Calculator() = default;

    void ExecuteOperation();
    bool OperatorCausesEvaluation(char op, char preOp);

    void ProcessClosingParenthesis();
    int ProcessInputNumber(std::string &exp, int pos);
    void ProcessInputOperator(char op);

    std::stack<double> vStack;
    std::stack<char> opStack;
};