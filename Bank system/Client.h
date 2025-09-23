
#pragma once
#include "Person.h"
#include<vector>
#include"Validation.h"





class Client : public Person {
    double balance;
public:
    Client():Person() {
        balance = 1500;
    }
    
    Client(int id, string name, string password, double balance) :Person() {
        this->balance = balance;
    }
    
   

    void setBalance(double b) { if (Validation::validateClientBalance(b)) balance = b; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) { cout << "money sholud more than zero.\n"; return; }
        balance += amount;
        cout << "money deposit " << amount <<  "credit now" << balance << endl;
    }
    bool withdraw(double amount) {
        if (amount <= 0) { cout << "money sholud more than zero.\n";  return false; }
        if (amount <= balance) { balance -= amount; cout  << amount <<"credit now" << balance << endl; return true; }
        cout << "not enogh credit"; return false;
    }
    bool transferTo(double amount, Client& recipient) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            cout << "transfer" << amount << "to " << recipient.getName() << endl;
            return true;
        }
        return false;
    }
    void checkBalance() {
        cout << balance << endl;
    }
    void display()  {
        cout << "Client => ID: " << id << " Name: " << name << "  Balance: " << balance << endl;
    }
};