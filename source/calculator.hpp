#include <chrono>
#include <thread>
#include <iostream>

struct MathCalculator {

    MathCalculator () {}

    int Addition(int a, int b);
    int Subtraction(int a, int b);
    int Mutiplication(int a, int b);
    int Division(int a, int b);

    // Function for solving a problem for addition, subtraction, mutiplication, and division
    int CalculateInt (std::string Operator, int a, int b);

    bool contains_number(std::string str) {
    	return (str.find_first_of("0123456789") != std::string::npos);
    }
};