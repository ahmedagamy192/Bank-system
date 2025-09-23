#pragma once
#include<iostream>
#include<string>
#include <cctype>
using namespace std;
class Validation {
public:
    static bool validateName( string name) {
        if (name.size() < 5 || name.size() > 20) return false;
        for (char c : name) if (!isalpha(c)) return false;
        return true;
    }
    static bool validatePassword( string pass) {
        return pass.size() >= 8 && pass.size() <= 20;
    }
    static bool validateClientBalance(double b) {
        return b >= 1500.0;
    }
    static bool validateSalary(double s) {
        return s >= 5000.0;
    }
};