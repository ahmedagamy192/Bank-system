#pragma once
#include"EmployeeManager.h"
class AdminManager
{
    FileManager& fm;
    vector<Employee> admins; // admins stored as Employee structure
    vector<Employee> employees; // regular employees
    ClientManager clientManager;
public:
    AdminManager(FileManager& _fm) : fm(_fm), clientManager(_fm) {
        admins = fm.getAllAdmins();
        employees = fm.getAllEmployees();
    }

    Admin* login(int id, const string& password) {
        for (auto& a_line : fm.getAllAdmins()) {
            
            if (a_line.getId() == id && a_line.getPassword() == password) {
                
     
                admins = fm.getAllAdmins();
                for (auto& a : admins) if (a.getId() == id && a.getPassword() == password) return reinterpret_cast<Admin*>(&a);
            }
        }
        return nullptr;
    }

    void printAdminMenu() {
        cout << "\n--- Admin Menu ---\n";
        cout << "1) Add New Client\n2) Add New Employee\n3) Search Client\n4) List Clients\n5) Edit Client\n6) Search Employee\n7) List Employees\n8) Edit Employee\n9) Logout\n";
    }

    bool adminOptions(Admin* admin) {
        
        admins = fm.getAllAdmins();
        employees = fm.getAllEmployees();
        clientManager.refreshFromFile();

        if (!admin) return false;
        while (true) {
            printAdminMenu();
            int opt; cout << "choice : "; cin >> opt; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt == 1) {
                int nid = fm.getNextClientId();
                string name, pass; double bal;
                cout << "client name :"; getline(cin, name);
                cout << "password: "; getline(cin, pass);
                cout << "balance"; cin >> bal; cin.ignore();
                if (!Validation::validateName(name) || !Validation::validatePassword(pass) || !Validation::validateClientBalance(bal)) {
                    cout << " invalid data\n";
                }
                else {
                    Client c(nid, name, pass, bal);
                    clientManager.getClients().push_back(c);
                    fm.saveAllClients(clientManager.getClients());
                    cout << "client has added and id = " << nid << endl;
                }
            }
            else if (opt == 2) {
                int nid = fm.getNextEmployeeId();
                string name, pass; double sal;
                cout << "empolyee name: "; getline(cin, name);
                cout << "password: "; getline(cin, pass);
                cout << "salary: "; cin >> sal; cin.ignore();
                if (!Validation::validateName(name) || !Validation::validatePassword(pass) || !Validation::validateSalary(sal)) {
                    cout << "invalid data\n";
                }
                else {
                    Employee e(nid, name, pass, sal);
                    employees.push_back(e);
                    fm.saveAllEmployees(employees);
                    cout << "empolye has saved and id = " << nid << endl;
                }
            }
            else if (opt == 3) {
                int sid; cout << "search for client : "; cin >> sid; cin.ignore();
                Client* c = nullptr;
                for (auto& cc : clientManager.getClients()) if (cc.getId() == sid) { c = &cc; break; }
                if (c) c->display(); else cout << "not found\n";
            }
            else if (opt == 4) {
                for ( auto& c : clientManager.getClients()) c.display();
            }
            else if (opt == 5) {
                int idToEdit; cout << "enter password to confirm "; cin >> idToEdit; cin.ignore();
                string newName, newPass; double newBal;
                cout << "new name :"; getline(cin, newName);
                cout << "new password :"; getline(cin, newPass);
                cout << "new cerdit : "; cin >> newBal; cin.ignore();
                Employee tmp;
                bool ok = tmp.editClient(clientManager.getClients(), idToEdit, newName, newPass, newBal);
                if (ok) {
                    fm.saveAllClients(clientManager.getClients());
                    cout << "saved.\n";
                }
                else {
                    cout << "failed to save\n";
                }
            }
            else if (opt == 6) {
                int sid; cout << "enter id  "; cin >> sid; cin.ignore();
                Employee* e = nullptr;
                for (auto& ee : employees) if (ee.getId() == sid) { e = &ee; break; }
                if (e) e->display(); else cout << "empolye not found.\n";
            }
            else if (opt == 7) {
                for ( auto& e : employees) e.display();
            }
            else if (opt == 8) {
                int idToEdit; cout << "enter ID "; cin >> idToEdit; cin.ignore();
                string newName, newPass; double newSal;
                cout << "name "; getline(cin, newName);
                cout << "password: "; getline(cin, newPass);
                cout << "salary: "; cin >> newSal; cin.ignore();
                Admin adminTmp;
                bool ok = adminTmp.editEmployee(employees, idToEdit, newName, newPass, newSal);
                if (ok) {
                    fm.saveAllEmployees(employees);
                    cout << "Employee saved\n";
                }
                else {
                    cout << "cannot save.\n";
                }
            }
            else if (opt == 9) {
                Screens::logout(); return true;
            }
            else {
                Screens::invalid(opt);
            }
        }
    }

};

