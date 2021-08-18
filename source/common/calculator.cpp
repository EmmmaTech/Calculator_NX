#include <calculator.hpp>

namespace
{

bool isOperator(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        return true;
        break;
    }

    return false;
}

} // namespace


Calculator &Calculator::getInstance()
{
    static Calculator c;
    return c;
}

double Calculator::evaluateExpression(std::string &exp)
{
    opStack.push('(');

    int pos = 0;
    while ((size_t)pos <= exp.length())
    {
        if ((size_t)pos == exp.length() || exp[pos] == ')')
        {
            ProcessClosingParenthesis();
            pos++;
        }

        else if (exp[pos] >= '0' && exp[pos] <= '9')
            pos = ProcessInputNumber(exp, pos);

        else if (isOperator(exp[pos]))
        {
            ProcessInputOperator(exp[pos]);
            pos++;
        }

        else pos++;
    }

    return vStack.top();
}

void Calculator::ExecuteOperation()
{
    double rightOper = vStack.top();
    vStack.pop();
    double leftOper = vStack.top();
    vStack.pop();

    char op = opStack.top();
    opStack.pop();

    double result = 0.0;
    switch (op)
    {
        case '+':
        result = leftOper + rightOper;
        break;

        case '-':
        result = leftOper - rightOper;
        break;

        case '*':
        result = leftOper * rightOper;
        break;

        case '/':
        result = leftOper / rightOper;
        break;

        case '^':
        result = pow(leftOper, rightOper);
        break;
    }

    vStack.push(result);
}

bool Calculator::OperatorCausesEvaluation(char op, char preOp)
{
    bool eval = false;

    switch (op)
    {
        case '+':
        case '-':
        eval = (preOp != '(');
        break;

        case '*':
        case '/':
        eval = (preOp == '*' || preOp == '/' || preOp == '^');
        break;

        case '^':
        eval = (preOp == '^');
        break;

        case ')':
        eval = true;
        break;
    }

    return eval;
}

void Calculator::ProcessClosingParenthesis()
{
    while (opStack.top() != '(')
        ExecuteOperation();

    opStack.pop();
}

int Calculator::ProcessInputNumber(std::string &exp, int pos)
{
    int numOfDecimalNums = 0;
    int posOfDecimalPoint = -1;

    double val = 0.0;
    while ((size_t)pos < exp.length() && ((exp[pos] >= '0' && exp[pos] <= '9') || exp[pos] == '.'))
    {
        if (exp[pos] == '.')
        {
            posOfDecimalPoint = pos++;
            continue;
        }

        if (pos > posOfDecimalPoint && posOfDecimalPoint > -1)
            numOfDecimalNums++;

        val = 10 * val + static_cast<int>(exp[pos++] - '0');
    }

    val /= pow(10, numOfDecimalNums);

    vStack.push(val);
    return pos;
}

void Calculator::ProcessInputOperator(char op)
{
    while (opStack.size() > 0 && OperatorCausesEvaluation(op, opStack.top()))
        ExecuteOperation();

    opStack.push(op);
}