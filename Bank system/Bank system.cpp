#include "FilesHelper.h"
#include"Filemanger.h"
#include"Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
int main()
{

    FileManager fm;
    Screens::bankName();

    ClientManager clientMgr(fm);
    EmployeeManager empMgr(fm);
    AdminManager adminMgr(fm);

    while (true) {
        Screens::welcome();
        int choice = Screens::loginAs();
        if (choice == 1) {
            // client login
            int id; string pass;
            cout << "Client ID: "; cin >> id; cin.ignore();
            cout << "Password: "; getline(cin, pass);
            clientMgr.refreshFromFile();
            Client* c = clientMgr.login(id, pass);
            if (c) {
                cout << "you are log in as aclient" << c->getName() << endl;
                clientMgr.clientOptions(c);
            }
            else {
                cout << "incorrect data\n";
            }
        }
        else if (choice == 2) {
            int id; string pass;
            cout << "Employee ID: "; cin >> id; cin.ignore();
            cout << "Password: "; getline(cin, pass);
            empMgr.refreshFromFile();
            Employee* e = empMgr.login(id, pass);
            if (e) {
                cout << "you are enter as Employee " << e->getName() << endl;
                empMgr.employeeOptions(e);
            }
            else {
                cout << "incorrect data\n";
            }
        }
        else if (choice == 3) {
            int id; string pass;
            cout << "Admin ID: "; cin >> id; cin.ignore();
            cout << "Password: "; getline(cin, pass);
            Admin* a = adminMgr.login(id, pass);
            if (a) {
                cout << "you are enter as admin " << a->getName() << endl;
                adminMgr.adminOptions(a);
            }
            else {
                cout << "incorrect data\n";
            }
        }
        else if (choice == 4) {
            cout << "Exit\n";
            break;
        }
        else {
            Screens::invalid(choice);
        }
        cout << "\n";
    }

    
}





