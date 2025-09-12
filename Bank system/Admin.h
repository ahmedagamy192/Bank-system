#pragma once
#include "Employee.h"
#include <fstream>
#include <string>
class Admin : public Employee
{
public:

	// constrctor

	Admin() :Employee() {
		this->salary = 0;
	}

	// constrctor par
	Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {

	}




	void saveToFile() {
		fstream file;
		string fileName = "Admin.txt";
		file.open("Admin.txt",ios::out| ios::app);
		file << "ID: " << id
			<< ", Name: " << name
			<< ", salary: " << salary
			<< ", password: " << password << endl;
		file.close();
		cout << " Client saved successfully!\n";

	}


};

