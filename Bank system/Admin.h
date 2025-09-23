#pragma once
#include "Employee.h"


class Admin : public Employee {

public:



    // constrctor

    Admin() :Employee() {
        this->salary = 0;
    }


    
    void addEmployee(vector<Employee>& employees, const Employee& e) {
        employees.push_back(e);
    }

    Employee* searchEmployee(vector<Employee>& employees, int searchId) {
        for (auto& e : employees) if (e.getId() == searchId) return &e;
        return nullptr;
    }

    void listEmployees( vector<Employee>& employees) {
        if (employees.empty()) { cout << "there are no employees\n"; return; }
        for ( auto& e : employees) e.display();
    }

    bool editEmployee(vector<Employee>& employees, int idToEdit, string& newName,
         string& newPass, double newSalary) {
        Employee* e = searchEmployee(employees, idToEdit);
        if (!e) return false;
        if (!Validation::validateName(newName) || !Validation::validatePassword(newPass) || !Validation::validateSalary(newSalary))
            return false;
        e->setName(newName);
        e->setPassword(newPass);
        e->setSalary(newSalary);
        return true;
    }
};
