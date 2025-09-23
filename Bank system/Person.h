#pragma once
#include "Validation.h"
class Person {
protected:
    int id;
    string name;
    string password;
public:
    Person() {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    Person(int id, string name, string password) {

        this->id = id;
        this->name = name;
        this->password = password;
    }
    

    void setId(int id) { id = id; }
    bool setName( string name) {
        if (Validation::validateName(name)) { name = name; return true; }
        return false;
    }
    bool setPassword( string pass) {
        if (Validation::validatePassword(pass)) { password = pass; return true; }
        return false;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }

    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};