#pragma once
#include "Praser.h"
#include <fstream>
using namespace std;

#define CLIENTS_FILE "data/Clients.txt"
#define EMPLOYEES_FILE "data/Employees.txt"
#define ADMINS_FILE "data/Admins.txt"

#define LAST_CLIENT_ID_FILE "data/Cliets_Id.txt"
#define LAST_EMPLOYEE_ID_FILE "data/Employees_Id.txt"
#define LAST_ADMIN_ID_FILE "data/Admins_Id.txt"


class FilesHelper {

public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName, ios::out);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(string fileName) {
        ifstream file(fileName, ios::in);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c) {

        ofstream file(CLIENTS_FILE, ios::app);
            
        if (file.is_open()) {
            file << c.getId() << "#" << c.getName() << "#"
                << c.getpassword() << "#" << c.getbalance() << endl;
            file.close();
            //saveLast(LAST_CLIENT_ID_FILE, c.getId());
        }
    }

    static void saveEmployee(Employee e) {
        ofstream file(EMPLOYEES_FILE, ios::app);
        if (file.is_open()) {
            file << e.getId() << "#" << e.getName() << "#"
                << e.getpassword() << "#" << e.getSalary() << endl;
            file.close();

            //saveLast(LAST_EMPLOYEE_ID_FILE, e.getId());
        }
    }

    static void saveAdmin(Admin a) {
        ofstream file(ADMINS_FILE, ios::app);
        if (file.is_open()) {
            file << a.getId() << "#" << a.getName() << "#"
                << a.getpassword() << "#" << a.getSalary() << endl;
            file.close();

            //saveLast(LAST_ADMIN_ID_FILE, a.getId());
        }
    }


    static void getClients() {
        // äÝÊÍ ÇáãáÝ ááÞÑÇÁÉ ÝÞØ
        ifstream file(CLIENTS_FILE);

        // áæ ÇáãáÝ ÝÔá Ýí ÇáÝÊÍ
        if (!file.is_open()) {
            cerr << "Error: cannot open file!" << endl;
            return;
        }

        string line;

        // äÞÑÃ ÇáãáÝ ÓØÑ ÈÓØÑ
        while (getline(file, line)) {
            // ßá ÓØÑ ÈÇáÔßá:  1#AhmedAgmy#Ahmed123#7000
            Client c = Praser::parseToClient(line);

            // äÖíÝ ÇáÚãíá Åáì ÇááíÓÊÉ
            allClients.push_back(c);
        }

        // ÈÚÏ ãÇ äÎáÕ ÞÑÇÁÉ äÞÝá ÇáãáÝ
        file.close();
    }



    //static void getClients() {
    //    fstream file;
    //    file.open(CLIENTS_FILE, ios::in);

    //    if (!file.is_open()) {
    //        cerr << "Error opening file\n";
    //        return;
    //    }

    //    string line;
    //    while (getline(file, line)) {
    //        // line => 1#AhmedAgmy#Ahmed123#7000 => Clinet

    //        Client c;
    //        c = Praser::parseToClient(line);
    //        allClients.push_back(c);

    //        //allClients.push_back(Praser::parseToClient(line));

    //    }
    //    file.close();
    //    
    //}











    //static vector<Employee> getEmployees() {
    //    vector<Employee> employees;
    //    ifstream file(EMPLOYEES_FILE);
    //    string line;

    //    if (file.is_open()) {
    //        while (getline(file, line)) {
    //            try {
    //                Employee employee = Parser::parseToEmployee(line);
    //                employees.push_back(employee);
    //            }
    //            catch (const exception& e) {
    //                cerr << "Error parsing employee: " << e.what() << endl;
    //            }
    //        }
    //        file.close();
    //    }

    //    return employees;
    //}

   
    //static void clearFile(string fileName) {
    //    ofstream file(fileName, ios::trunc);
    //    if (file.is_open()) {
    //        file.close();
    //    }
    //}
};







