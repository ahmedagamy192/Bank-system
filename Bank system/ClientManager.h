#pragma once
#include"Filemanger.h"
#include"Screens.h"
class ClientManager
{
    FileManager& fm;
    vector<Client> clients;
public:
    ClientManager(FileManager& fm) : fm(fm) { clients = fm.getAllClients(); }

    Client* login(int id, const string& password) {
        for (auto& c : clients) if (c.getId() == id && c.getPassword() == password) return &c;
        return nullptr;
    }

    void printClientMenu() {
        cout << "\n--- Client Menu ---\n";
        cout << "1) Deposit\n2) Withdraw\n3) Transfer\n4) Check Balance\n5) Display Info\n6) Logout\n";
    }

    bool clientOptions(Client* client) {
        if (!client) return false;
        while (true) {
            printClientMenu();
            int opt; cout << "choice : "; cin >> opt; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt == 1) {
                double amt; cout << "deposit money "; cin >> amt; cin.ignore();
                client->deposit(amt);
                fm.saveAllClients(clients); 
            }
            else if (opt == 2) {
                double amt; cout << "withdrwal money: "; cin >> amt; cin.ignore();
                if (client->withdraw(amt)) fm.saveAllClients(clients);
            }
            else if (opt == 3) {
                int rid; double amt; cout << "enter id "; cin >> rid;
                cout << "transfer money "; cin >> amt; cin.ignore();
                Client* rec = nullptr;
                for (auto& c : clients) if (c.getId() == rid) { rec = &c; break; }
                if (!rec) cout << " client not found\n";
                else {
                    if (client->transferTo(amt, *rec)) fm.saveAllClients(clients);
                }
            }
            else if (opt == 4) {
                client->checkBalance();
            }
            else if (opt == 5) {
                client->display();
            }
            else if (opt == 6) {
                Screens::logout(); return true;
            }
            else {
                Screens::invalid(opt);
            }
        }
    }

   
    vector<Client>& getClients() { return clients; }
    void refreshFromFile() { clients = fm.getAllClients(); }
};


