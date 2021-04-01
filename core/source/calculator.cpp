#include <calculator.hpp>

namespace Calculator {

    // New methods involving Variadic Templates
    float Addition() {
        return 0; 
    }
    float Subtraction() {
        return 0;
    }
    float Mutiplication() {
        return 1;
    }
    float Division() {
        return 1;
    }

    template <typename T, typename... Types>
    float Addition(T var, Types... rest) {
        return var + Addition(rest...);
    }

    template <typename T, typename... Types>
    float Subtraction(T var, Types... rest) {
        return var - Subtraction(rest...);
    }

    template <typename T, typename... Types>
    float Mutiplication(T var, Types... rest) {
        return var * Mutiplication(rest...);
    }

    template <typename T, typename... Types>
    float Division(T var, Types... rest) {
        return var / Division(rest...);
    }

    namespace Convert {
        int turnStringToIntOperator (const std::string& string) {
            if (string == "+" || string == "-" || string == "*" || string == "/") {
                if (string == "+") return 1;
                if (string == "-") return 2;
                if (string == "*") return 3;
                if (string == "/") return 4;
            } else return 0;

            return 0; 
        }
    }

    float solve(std::vector<float>& vec, const std::string& operation) {
        float result = vec[0];

        for (std::vector<float>::size_type i{ 1 }; i < vec.size(); i++) {
            auto current_num = vec[i];

            switch (Convert::turnStringToIntOperator(operation)) {
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

    float solve(std::string numbers, const std::string& operation) {
        std::istringstream iss(numbers);
        std::string current_str_num;

        std::deque<float> num_deque;

        while (iss >> current_str_num) {
            num_deque.emplace_back(std::stof(current_str_num));
        }

        float answer = num_deque[0];
        
        for (size_t i{ 1 }; i < num_deque.size(); i++) {
            switch (Convert::turnStringToIntOperator(operation)) {
            case 1: {
                    answer = Addition(answer, num_deque[i]);
                    break;
            }

            case 2: {
                    answer = Subtraction(answer, num_deque[i]);
                    break;
            }

            case 3: {
                    answer = Mutiplication(answer, num_deque[i]);
                    break;
            }

            case 4: {
                    answer = Division(answer, num_deque[i]);
                    break;
            }

            default:
                    break;
            }
        }

        return answer;
    }
}