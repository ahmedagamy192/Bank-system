#pragma once
#include "Employee.h"
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
};

