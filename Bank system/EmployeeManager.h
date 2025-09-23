#pragma once
#include"ClientManager.h"
class EmployeeManager
{
    
        FileManager& fm;
        vector<Employee> employees;
        ClientManager clientManager; 
    public:
        EmployeeManager(FileManager& _fm) : fm(fm), clientManager(fm) {
            employees = fm.getAllEmployees();
        }

        Employee* login(int id, const string& password) {
            for (auto& e : employees) if (e.getId() == id && e.getPassword() == password) return &e;
            return nullptr;
        }

        void printEmployeeMenu() {
            cout << "\n--- Employee Menu ---\n";
            cout << "1) Add New Client\n2) Search Client by ID\n3) List All Clients\n4) Edit Client\n5) Logout\n";
        }

        bool employeeOptions(Employee* employee) {
            if (!employee) return false;
            while (true) {
                printEmployeeMenu();
                int opt; cout << "choice : "; cin >> opt; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (opt == 1) {
                    // add client
                    int nid = fm.getNextClientId();
                    string name, pass; double bal;
                    cout <<"client name :"; getline(cin, name);
                    cout << "password "; getline(cin, pass);
                    cout << "credit : "; cin >> bal; cin.ignore();
                    if (!Validation::validateName(name) || !Validation::validatePassword(pass) || !Validation::validateClientBalance(bal)) {
                        cout << "invalid data\n";
                    }
                    else {
                        Client c(nid, name, pass, bal);
                        clientManager.getClients().push_back(c);
                        fm.saveAllClients(clientManager.getClients());
                        cout << " clients have saved and ID = " << nid << endl;
                    }
                }
                else if (opt == 2) {
                    int sid; cout << "enter id to serch "; cin >> sid; cin.ignore();
                    Client* c = nullptr;
                    for (auto& cc : clientManager.getClients()) if (cc.getId() == sid) { c = &cc; break; }
                    if (c) c->display(); else cout <<" not found \n;"
                }
                else if (opt == 3) {
                    clientManager.getClients(); 
                    clientManager.refreshFromFile();
                    clientManager.getClients();
                    for ( auto& c : clientManager.getClients()) c.display();
                }
                else if (opt == 4) {
                    int idToEdit; cout << "enter id  "; cin >> idToEdit; cin.ignore();
                    string newName, newPass; double newBal;
                    cout << "new name: "; getline(cin, newName);
                    cout << "new password: "; getline(cin, newPass);
                    cout << "new credit: "; cin >> newBal; cin.ignore();
                    Employee tmp; 
                    bool ok = tmp.editClient(clientManager.getClients(), idToEdit, newName, newPass, newBal);
                    if (ok) {
                        fm.saveAllClients(clientManager.getClients());
                        cout << "claients have saved\n";
                    }
                    else {
                        cout << "un correct data.\n";
                    }
                }
                else if (opt == 5) {
                    Screens::logout(); return true;
                }
                else {
                    Screens::invalid(opt);
                }
            }
        }

        // admins need access to employees vector too
        vector<Employee>& getEmployees() { return employees; }
        void refreshFromFile() { employees = fm.getAllEmployees(); clientManager.refreshFromFile(); }
        ClientManager& getClientManager() { return clientManager; }
    

};

