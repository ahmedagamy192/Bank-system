#pragma once
#include<iostream>
#include<string>

using namespace std;
class Validation
{
public:

	static bool checkName(string name) {
		if ( !(name.size() >= 5 && name.size() <= 20) ) {
			cout << "invalid name\n";
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				cout << " invalid name\n";
				return false;
			}

		}
		return true;
	}


	//ckeck password


	static bool checkPassword(string password) {

		if (!(password.size() >= 8 && password.size() <= 20))
		{
			cout << " invalid name\n";
			return false;
		}

		return true;
	}


	//check balance


	static bool checkBalance(double balance) {
		if (balance < 1500) {
			cout << " balance less 1500\n"; return false;
		}

		return true;
	}


	// check salary


	static bool checksalary(double salary) {
		if (salary < 5000) {
			cout << " salary less 5000\n"; return false;
		}

		return true;

	}

};

