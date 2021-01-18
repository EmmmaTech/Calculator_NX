#include <chrono>
#include <thread>
#include <iostream>
#include <cstdlib>

struct MathCalculator {
    MathCalculator () {}
    MathCalculator (int newA, int newB) {
        newA = a;
        newB = b;

        //std::cout << newA << " " << this -> a << " " << newB << " " << this -> b << "\n";
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

    void setA(int new_int) {
        this -> a = new_int;
    }

    void setB(int new_int) {
        this -> b = new_int;
    }

    std::string compareNumberString(bool result, std::string str, MathCalculator* math, int decider) {
        if (result){
            int number = std::stoi(str);
            if (decider == 1) math -> setA(number);
            else if (decider == 2) math -> setB(number);
            else return "NULL";

            return "NUMBER";
        }
        else return "LETTER";
        

        return "NULL";
    }

};