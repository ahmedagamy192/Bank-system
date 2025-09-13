#include "Admin.h"
#include <fstream>
#include "FilesHelper.h"


int main()
{

	/*Admin(double salary, int id, string name, string password)*/
	
	Admin a(7000.0, 1, "AhmedAgmy", "Ahmed123");
	Fileshelper::saveToFile(a);
	a.displayInfo();
	
}

