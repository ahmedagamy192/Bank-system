#pragma once
#include <iostream>   
#include <fstream>    
#include <sstream>    
#include <vector>    
#include <string>
#include"Admin.h"
#include"Client.h"
#include"Employee.h"
#include"Person.h"

using namespace std;
class Praser 
{
public:
	static vector<string>split(string line, char c = '#') {

		vector <string> result;
		stringstream s(line);
		string temp;
		while (getline(s, temp, c)) {
			result.push_back(temp);
		}

		return result;
	}
	


	static Client parseToClient(string line) {
		vector<string> parts = split(line);
		int id = stoi(parts[0]);         
		string name = parts[1];
		string pw = parts[2];
		double balance = stod(parts[3]); 
		return Client(balance,  id ,name, password);
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





