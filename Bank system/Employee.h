#pragma once
#include "Client.h"
class Employee : public Person
{
protected:
	double salary;
public:

	// constrctor


	Employee() :Person() {
		this->salary = 0;
	}

	// constrctor par

	Employee(double salary, int id, string name, string password) :Person(id, name, password) {
		setsalary(salary);
	}

	//setter

	void setsalary(double salary) {
		if (Validation::checksalary(salary))
			this->salary = salary;
		else cout << "invalid salary" << endl;
	}

	// getters

	double getSalary() const { return salary; }


	// methodes

	void displayInfo()const {
		Person::displayInfo();
		cout << "salary :" << salary << endl;
	}
};

