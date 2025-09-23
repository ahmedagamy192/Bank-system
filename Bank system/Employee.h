#pragma once
#include"Person.h"
#include"Client.h"



class Employee : public Person {

protected:
    double salary;
public:
    Employee() : Person(), salary(5000.0) {}
    Employee(int id,  string name, string pass, double salary)
        : Person(id, name, pass), salary(salary >= 5000.0 ? salary : 5000.0) {
    }

    void setSalary(double s) { if (Validation::validateSalary(s)) salary = s; }
    double getSalary() const { return salary; }

    virtual void display() {
        cout << "Employee => ID: " << id << " | Name: " << name << " | Salary: " << salary << endl;
    }

    // operates on provided collection (vectors)
    void addClient(vector<Client>& clients, const Client& c) {
        clients.push_back(c);
    }

    Client* searchClient(vector<Client>& clients, int searchId) {
        for (auto& c : clients) if (c.getId() == searchId) return &c;
        return nullptr;
    }

    void listClients(vector<Client>& clients) {
        if (clients.empty()) { cout << "no clients.\n"; return; }
        for ( auto& c : clients) c.display();
    }

    bool editClient(vector<Client>& clients, int idToEdit,  string& newName,
        string& newPass, double newBalance) {
        Client* c = searchClient(clients, idToEdit);
        if (!c) return false;
        if (!Validation::validateName(newName) || !Validation::validatePassword(newPass) || !Validation::validateClientBalance(newBalance))
            return false;
        c->setName(newName);
        c->setPassword(newPass);
        c->setBalance(newBalance);
        return true;
    }
};

