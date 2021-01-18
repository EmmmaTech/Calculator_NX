#include <chrono>
#include <thread>
#include <iostream>

struct MathCalculator {
    MathCalculator () {}
    MathCalculator (int newA, int newB) {
        newA = this -> a;
        newB = this -> b;
    }

    int a = 0;
    int b = 0;

    int Addition(int a, int b);
    int Subtraction(int a, int b);
    int Mutiplication(int a, int b);
    int Division(int a, int b);

    int Addition();
    int Subtraction();
    int Mutiplication();
    int Division();

    // Function for solving a problem for addition, subtraction, mutiplication, and division
    int CalculateInt (std::string Operator, int a, int b);
    int CalculateInt (std::string Operator);

    bool contains_number(std::string str) {
    	return (str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos);
    }

    int getAorB(int decider) {
        if (decider == 1) return a;
        else if (decider == 2) return b;
        else return 0;
        return 0;
    } 

    void setAorB(int decider, int &new_int) {
        if (decider == 1) setA(new_int);
        else if (decider == 2)  setB(new_int);

        std::cout << this -> a << " " << this -> b << "\n"; 
    }

    void setA(int &new_int) {
        int& newA = a;
        newA = new_int;
    }

    void setB(int &new_int) {
        int& newB = b;
        newB = new_int;
    }

};