#pragma once
#include "Admin.h"

class DataSourceInterface {
protected:
	virtual void addClient(const Client& c) = 0;
	virtual void addEmployee(const Employee& e) = 0;
	virtual void addAdmin(const Admin& a) = 0;
	
	virtual vector<Client> getAllClients() const = 0;
	virtual vector<Employee> getAllEmployees() const = 0;
	virtual vector<Employee> getAllAdmins() const = 0;
	
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};