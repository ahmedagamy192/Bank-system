#pragma once
#include<iostream>
using namespace std;

    class Screens {
    public:
        static void bankName() {
            cout << "=====================================\n";
            cout << "      Welcome to Egupt Bank      \n";
            cout << "=====================================\n";
        }
        static void welcome() {
            cout << "\n hello choice how to log in :\n";
            cout << "1) Login as Client\n2) Login as Employee\n3) Login as Admin\n4) Exit\n";
        }
        static int loginAs() {
            int c;
            cout << "choice: "; cin >> c; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        }
        static void invalid(int c) {
            cout << "in valid choice " << c << "\n";
        }
        static void logout() {
            cout << "you are log out\n";
        }
        static void pause() {
            cout << "\n push enter to contine"; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    };






