#pragma once
#include <sstream>    
#include <vector>    
#include"Admin.h"

using namespace std;
class Praser 
{
	static vector<string>split(string line, char c = '#') {
		// 1#Ahmed123#AhmedAgmy#7000
		vector <string> result;
		stringstream s(line);
		string temp;
		while (getline(s, temp, c)) {
			result.push_back(temp);
		}
		// result[0] = id         => string
		// result[1] = name      => string
		// result[2] = password   => string
		// result[3] = balance     => string
		return result;
	}

public:

	

	static Client parseToClient(string line) {

		vector<string> parts = split(line);

		int id = stoi(parts[0]);         
		string name = parts[1];
		string pw = parts[2];
		double balance = stod(parts[3]); 
		return Client(balance,  id ,name, pw);

	}


	static Employee parseToEmployee(string line) {

		vector<string> parts = split(line);
		int id = stoi(parts[0]);
		string name = parts[1];
		string pw = parts[2];
		double salary = stod(parts[3]);
		return Employee(salary,id, name, pw);
	}


	static Admin parseToAdmin(string line) {

		vector<string> parts = split(line);
		int id = stoi(parts[0]);
		string name = parts[1];
		string pw = parts[2];
		double salary = stod(parts[3]);
		return Admin(salary,id, name, pw);
	}


};





