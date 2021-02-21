#include "calculator.hpp"

namespace Calculator {
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

        for (std::vector<float>::size_type i{ 1 }; i < vec.size(); i++) {
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