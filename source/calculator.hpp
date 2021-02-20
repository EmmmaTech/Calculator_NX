#pragma once

#include <iostream>
#include <vector>
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
        static T Addition(T a, T b) {
            T answer{};
            answer = a + b;
            return answer;
        }
        static T Subtraction(T a, T b) {
            T answer{};
            answer = a - b;
            return answer;
        }
        static T Mutiplication(T a, T b) {
            T answer{};
            answer = a * b;
            return answer;
        }
        static T Division(T a, T b) {
            T answer{};
            answer = a / b;
            return answer;
        }

        // Older method that solves only 2 numbers at a time
        T CalculateInt(std::string Operator, T a, T b) {
            // Find out what operator the user is using, then solve
            if (Operator == "+" || Operator == "addition") return this->Addition(a, b);
            if (Operator == "-" || Operator == "subtraction") return this->Subtraction(a, b);
            if (Operator == "*" || Operator == "mutiplication") return this->Mutiplication(a, b);
            if (Operator == "/" || Operator == "division") return this->Division(a, b);

            // Returns the answer for another variable
            return 0;
        }

        // Alternative method using std::vectors, newer one is recommended
        T CalculateMoreInt(std::string_view Operator) {
            T answer = VectorCalculator[0];
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

        bool contains_number(std::string str) {
            return (str.find_first_of("0123456789") != std::string::npos);
        }

        static int turnStringToIntOperator (std::string_view string) {
            if (string == "+" || string == "-" || string == "*" || string == "/") {
                if (string == "+") return 1;
                if (string == "-") return 2;
                if (string == "*") return 3;
                if (string == "/") return 4;
            } else return 0;

            return 0; 
        }

        void setVector(T newInt){
            VectorCalculator.emplace_back(newInt);
        }

        private:
        std::vector<T> VectorCalculator;
    };

    // New methods involving Variadic Templates
    static float Addition() {
        return 0; 
    }

    static float Subtraction() {
        return 0;
    }

    static float Mutiplication() {
        return 1;
    }

    static float Division() {
        return 1;
    }


    template <typename T, typename... Types>
    static float Addition(T var, Types... rest) {
        return var + Addition(rest...);
    }

    template <typename T, typename... Types>
    static float Subtraction(T var, Types... rest) {
        return var - Subtraction(rest...);
    }

    template <typename T, typename... Types>
    static float Mutiplication(T var, Types... rest) {
        return var * Mutiplication(rest...);
    }

    template <typename T, typename... Types>
    static float Division(T var, Types... rest) {
        return var / Division(rest...);
    }

    static int turnStringToIntOperator (std::string_view string) {
        if (string == "+" || string == "-" || string == "*" || string == "/") {
            if (string == "+") return 1;
            if (string == "-") return 2;
            if (string == "*") return 3;
            if (string == "/") return 4;
        } else return 0;

        return 0; 
    }

    // Newer method for solving "infinite" amount of numbers, still involves std::vector
    // Instead of deleting the first number in the std::vector, this approach loops through all the elements in the std::vector
    // This in the end is easier to use
    float solve(std::vector<float>& vec, std::string_view operation) {
        float result = vec[0];

        for (int i = 1; i < vec.size(); i++) {
            auto current_num = vec[i];

            switch (turnStringToIntOperator(operation)) {
                case 1: {
                    result += Addition(current_num);
                    break;
                }
                case 2: {
                    result -= Subtraction(current_num);
                    break;
                }
                case 3: {
                    result *= Mutiplication(current_num);
                    break;
                }
                case 4: {
                    result /= Division(current_num);
                    break;
                }
            }
        }

        return result;
    }
}
