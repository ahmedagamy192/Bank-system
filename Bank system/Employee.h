#pragma once
#include "Person.h"
#include <fstream>
#include <string>
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

	double getbalance() const { return salary; }


	// methodes

	void displayInfo()const {
		Person::displayInfo();
		cout << "salary :" << salary << endl;
	}





	void saveToFile() {
		fstream file;
		string fileName = "Employee.txt";
		file.open("Employee.txt", ios::app);
		file << "ID: " << id
			<< ", Name: " << name
			<< ", salary: " << salary
			<< ", password: " << password << endl;
		file.close();
		cout << " Employee saved successfully!\n";

	}



};

