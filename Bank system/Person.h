#pragma once
#include "Validation.h"
class Person
{
protected:
	int id;
	string name;
	string password;
public:

	//constrctor
	Person() {
		this->id = 0;
	}

	// paramterize constrctor

	Person(int id, string name, string password) {
		this->id = id;
		setName(name);
		setpassword(password);
	}

	//seters
	void setName(string name) {
		if (Validation::checkName(name)) {
			this->name = name;
		}
		else cout << " invalid name\n";
	}


	void setpassword(string password) {
		if (Validation::checkPassword(password)) {
			this->password = password;
		}
		else cout << " invalid password\n";


	}

	void setid(int id) { this->id = id; }



	//getters




	string getName() { return this->name; }
	string getpassword() { return this->password; }
	int getId() const { return this->id; }

	//methodes

	virtual void displayInfo() const {
		cout << "name : " << name << endl;
		cout << "password : " << password << endl;
		cout << "id : " << id << endl;
	}

};

