#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <utility>

struct MathCalculator {

    MathCalculator () {}
    MathCalculator (std::vector<int> Vector) : VectorCalculator{ Vector } {}
    
    // Smaller functions for solving problems. Used mostly in the function below
    int Addition(int a, int b);
    int Subtraction(int a, int b);
    int Mutiplication(int a, int b);
    int Division(int a, int b);

    // Function for solving a problem for addition, subtraction, mutiplication, and division
    int CalculateInt(std::string Operator, int a, int b);
    int CalculateMoreInt(std::string_view Operator);

    bool contains_number(std::string str) {
    	return (str.find_first_of("0123456789") != std::string::npos);
    }

    int turnStringToIntOperator (std::string_view string) {
        if (string == "+" || string == "-" || string == "*" || string == "/") {
            if (string == "+") return 1;
            if (string == "-") return 2;
            if (string == "*") return 3;
            if (string == "/") return 4;
        } else return 0;

        return 0; 
    }

    void setVector(int newInt){
        VectorCalculator.emplace_back(newInt);
    }

    private:
    std::vector<int> VectorCalculator;
};
