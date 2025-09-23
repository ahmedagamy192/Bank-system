#pragma once
#include <sstream>    
#include <vector>    
#include"Admin.h"

using namespace std;

class Parser {
public:
    static vector<string> split(const string& line, char delim = '#') {
        vector<string> parts;
        stringstream ss(line);
        string item;
        while (getline(ss, item, delim)) parts.push_back(item);
        return parts;
    }

    static Client parseToClient(const string& line) {
        auto p = split(line);
        if (p.size() < 4) return Client();
        int id = stoi(p[0]);
        string name = p[1];
        string pass = p[2];
        double bal = stod(p[3]);
        return Client(id, name, pass, bal);
    }

    static Employee parseToEmployee(const string& line) {
        auto p = split(line);
        if (p.size() < 4) return Employee();
        int id = stoi(p[0]);
        string name = p[1];
        string pass = p[2];
        double sal = stod(p[3]);
        return Employee(id, name, pass, sal);
    }

    static Admin parseToAdmin(const string& line) {
        auto p = split(line);
        if (p.size() < 4) return Admin();
        int id = stoi(p[0]);
        string name = p[1];
        string pass = p[2];
        double sal = stod(p[3]);
        return Admin(id, name, pass, sal);
    }
};