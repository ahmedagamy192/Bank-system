#pragma once
#include"DataSourceInterface.h"
#include"FilesHelper.h"

class FileManager : public DataSourceInterface {
    string clientsFile = "clients.txt";
    string employeesFile = "employees.txt";
    string adminsFile = "admins.txt";

    string lastClientIdFile = "last_client_id.txt";
    string lastEmployeeIdFile = "last_employee_id.txt";
    string lastAdminIdFile = "last_admin_id.txt";

public:
    FileManager() {
        FilesHelper::ensureFileExists(clientsFile);
        FilesHelper::ensureFileExists(employeesFile);
        FilesHelper::ensureFileExists(adminsFile);
        FilesHelper::ensureFileExists(lastClientIdFile);
        FilesHelper::ensureFileExists(lastEmployeeIdFile);
        FilesHelper::ensureFileExists(lastAdminIdFile);
    }

    // --- Adders ---
    void addClient(const Client& c)  {
        stringstream ss;
        ss << c.getId() << "#" << c.getName() << "#" << c.getPassword() << "#" << c.getBalance();
        FilesHelper::appendLine(clientsFile, ss.str());
        FilesHelper::saveLast(lastClientIdFile, c.getId());
    }
    void addEmployee(const Employee& e)  {
        stringstream ss;
        ss << e.getId() << "#" << e.getName() << "#" << e.getPassword() << "#" << e.getSalary();
        FilesHelper::appendLine(employeesFile, ss.str());
        FilesHelper::saveLast(lastEmployeeIdFile, e.getId());
    }
    void addAdmin(const Admin& a) {
        stringstream ss;
        ss << a.getId() << "#" << a.getName() << "#" << a.getPassword() << "#" << a.getSalary();
        FilesHelper::appendLine(adminsFile, ss.str());
        FilesHelper::saveLast(lastAdminIdFile, a.getId());
    }

    // --- Getters ---
    vector<Client> getAllClients() const {
        vector<Client> out;
        auto lines = FilesHelper::readAllLines(clientsFile);
        for (auto& l : lines) out.push_back(Parser::parseToClient(l));
        return out;
    }
    vector<Employee> getAllEmployees() const {
        vector<Employee> out;
        auto lines = FilesHelper::readAllLines(employeesFile);
        for (auto& l : lines) out.push_back(Parser::parseToEmployee(l));
        return out;
    }
    vector<Employee> getAllAdmins() const {
        vector<Employee> out;
        auto lines = FilesHelper::readAllLines(adminsFile);
        for (auto& l : lines) out.push_back(Parser::parseToEmployee(l)); // parse same structure
        return out;
    }

    // --- Remove All ---
    void removeAllClients()  {
        FilesHelper::clearFile(clientsFile);
        FilesHelper::saveLast(lastClientIdFile, 0);
    }
    void removeAllEmployees()  {
        FilesHelper::clearFile(employeesFile);
        FilesHelper::saveLast(lastEmployeeIdFile, 0);
    }
    void removeAllAdmins()  {
        FilesHelper::clearFile(adminsFile);
        FilesHelper::saveLast(lastAdminIdFile, 0);
    }

    // --- Helpers to get next id (useful for managers) ---
    int getNextClientId() {
        int last = FilesHelper::getLast(lastClientIdFile);
        return last + 1;
    }
    int getNextEmployeeId() {
        int last = FilesHelper::getLast(lastEmployeeIdFile);
        return last + 1;
    }
    int getNextAdminId() {
        int last = FilesHelper::getLast(lastAdminIdFile);
        return last + 1;
    }

    // --- Helpers to overwrite all data from vectors (write entire vector to file) ---
    void saveAllClients(const vector<Client>& clients) {
        removeAllClients();
        for (const auto& c : clients) addClient(c);
    }
    void saveAllEmployees(const vector<Employee>& employees) {
        removeAllEmployees();
        for (const auto& e : employees) addEmployee(e);
    }
    void saveAllAdmins(const vector<Employee>& admins) {
        removeAllAdmins();
        for (const auto& a : admins) {
            // cast employee to admin-like row
            stringstream ss;
            ss << a.getId() << "#" << a.getName() << "#" << a.getPassword() << "#" << a.getSalary();
            FilesHelper::appendLine(adminsFile, ss.str());
            FilesHelper::saveLast(lastAdminIdFile, a.getId());
        }
    }
};