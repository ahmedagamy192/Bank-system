#pragma once
#include "Person.h"
#include <fstream>
#include <string>

class Client : public Person
{
private:
	double balance;
public:

	// constrctor

	Client() : Person() {
		this->balance = 0;
	}

	// constrctor par
	Client(double balance, int id, string name, string password) :Person(id, name, password) {
		setbalane(balance);
	}



	//setter

	void setbalane(double balance) {
		if (Validation::checkBalance(balance))
			this->balance = balance;
		else cout << "invalid balance" << endl;
	}

	// getters

	double getbalance() const { return balance; }


	// methodes

	void deposit(double amount) {
		balance += amount;
	}


	void  withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
		}
		else  cout << "balance not enough\n ";


	}

	void transfer(double amount, Client& c) {
		if (balance >= amount) {
			balance -= amount;
		}
		c.deposit(amount);
	}


	void checkBalance() const {
		cout << "balance :" << balance << endl;
	}

	void displayInfo()const {
		Person::displayInfo();
		cout << "balance :" << balance << endl;
	}

};
