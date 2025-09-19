//#pragma once
//#include<string>
//#include"DataSourceInterface.h"
//#include"FilesHelper.h"
//using namespace std;
//class Filemanger:public DataSourceInterface{
//
//
//private:
//    string clientsFile = "clients.txt";
//    string employeesFile = "employees.txt";
//    string adminsFile = "admins.txt";
//    string lastClientFile = "last_client_id.txt";
//    string lastEmployeeFile = "last_employee_id.txt";
//    string lastAdminFile = "last_admin_id.txt";
//
//public:
//
//    class FileManager : public DataSourceInterface {
//    private:
//        vector<Client> clients;
//        vector<Employee> employees;
//        vector<Admin> admins;
//
//    public:
//        FileManager() {
//          
//            clients = FilesHelper::getClients();
//            employees = FilesHelper::getEmployees();
//            admins = FilesHelper::getAdmins();
//        }
//
//        void addClient(Client client) {
//            clients.push_back(client);
//            FilesHelper::saveClient(client);
//        }
//
//        void addEmployee(Employee employee)  {
//            employees.push_back(employee);
//            FilesHelper::saveEmployee(employee);
//        }
//
//        void addAdmin(Admin admin) {
//            admins.push_back(admin);
//            FilesHelper::saveAdmin(admin);
//        }
//
//        vector<Client> getAllClients()  {
//            return clients;
//        }
//
//        vector<Employee> getAllEmployees()  {
//            return employees;
//        }
//
//        vector<Admin> getAllAdmins()  {
//            return admins;
//        }
//
//        void removeAllClients()  {
//            clients.clear();
//            FilesHelper::clearFile(FilesHelper::CLIENTS_FILE);
//            FilesHelper::saveLast(FilesHelper::LAST_CLIENT_ID_FILE, 0);
//        }
//
//        void removeAllEmployees()  {
//            employees.clear();
//            FilesHelper::clearFile(FilesHelper::EMPLOYEES_FILE);
//            FilesHelper::saveLast(FilesHelper::LAST_EMPLOYEE_ID_FILE, 0);
//        }
//
//        void removeAllAdmins() {
//            admins.clear();
//            FilesHelper::clearFile(FilesHelper::ADMINS_FILE);
//            FilesHelper::saveLast(FilesHelper::LAST_ADMIN_ID_FILE, 0);
//        }
//
//        
//        Client* getClientById(int id) {
//            for (auto& client : clients) {
//                if (client.getId() == id) {
//                    return &client;
//                }
//            }
//            return nullptr;
//        }
//
//        Employee* getEmployeeById(int id) {
//            for (auto& employee : employees) {
//                if (employee.getId() == id) {
//                    return &employee;
//                }
//            }
//            return nullptr;
//        }
//
//        Admin* getAdminById(int id) {
//            for (auto& admin : admins) {
//                if (admin.getId() == id) {
//                    return &admin;
//                }
//            }
//            return nullptr;
//        }
//    };
//};
//
