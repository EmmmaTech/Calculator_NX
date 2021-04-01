#ifndef CORE_CALCULATOR_INCLUDED
#define CORE_CALCULATOR_INCLUDED

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <type_traits>

namespace Calculator {

    template <typename T>
    struct MathCalculator {

        MathCalculator () {}
        MathCalculator (std::vector<T> Vector) : VectorCalculator{ Vector } {
            static_assert(std::is_arithmetic<T>(), "Type must support Math operations");
            static_assert(std::is_default_constructible<T>(), "Type must be Default Constructible");
        }
        
        // Smaller functions for solving problems. Used mostly in the function below
        T OldAddition(T a, T b) {
            T answer{};
            answer = a + b;
            return answer;
        }
        T OldSubtraction(T a, T b) {
            T answer{};
            answer = a - b;
            return answer;
        }
        T OldMutiplication(T a, T b) {
            T answer{};
            answer = a * b;
            return answer;
        }
        T OldDivision(T a, T b) {
            T answer{};
            answer = a / b;
            return answer;
        }

        // Older method that solves only 2 numbers at a time
        T CalculateInt(std::string Operator, T a, T b) {
            // Find out what operator the user is using, then solve
            if (Operator == "+" || Operator == "addition") return this->OldAddition(a, b);
            if (Operator == "-" || Operator == "subtraction") return this->OldSubtraction(a, b);
            if (Operator == "*" || Operator == "mutiplication") return this->OldMutiplication(a, b);
            if (Operator == "/" || Operator == "division") return this->OldDivision(a, b);

            // Returns the answer for another variable
            return 0;
        }

        // Alternative method using std::vectors, newer one is recommended
        /*T CalculateMoreInt(const std::string& Operator) {
            T answer = VectorCalculator[0];
            VectorCalculator.erase(VectorCalculator.begin());

            while (!VectorCalculator.empty()) {
                switch (Calculator::Convert::turnStringToIntOperator(Operator)) {
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
        } TODO: Restore*/

        bool contains_number(std::string str) {
            return (str.find_first_of("0123456789") != std::string::npos);
        }

        void setVector(T newInt){
            VectorCalculator.emplace_back(newInt);
        }

        private:
        std::vector<T> VectorCalculator;
    };

    namespace Convert {
        int turnStringToIntOperator (const std::string& string);
    }

    // Newer method for solving "infinite" amount of numbers, still involves std::vector
    // Instead of deleting the first number in the std::vector, this approach loops through all the elements in the std::vector
    // This in the end is easier to use
    float solve(std::vector<float>& vec, const std::string& operation);

    float solve(std::string numbers, const std::string& operation);
}
#endif // #ifndef CORE_CALCULATOR_INCLUDED