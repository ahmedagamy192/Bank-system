#pragma once
#include"Admin.h"
#include"Client.h"
#include<fstream>
using namespace std;
class Fileshelper
{
public:
	static void saveToFile(Admin a) {
		fstream file;
		string fileName = "Admin.txt";
		file.open("Admin.txt", ios::out | ios::app);
		file << a.getId() << '#' << a.getName() << '#' << a.getbalance() << "#" << a.getpassword() << endl;
		file.close();
		//cout << " Client saved successfully!\n";

	}
 
};