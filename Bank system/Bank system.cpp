#include "FilesHelper.h"
int main()
{
	//string testline = "1#AhmedAgmy#Ahmed123#7000";

	//Admin c(7000, 1, "AhmedAgmy", "Ahmed123");
	//FilesHelper::saveAdmin(c);

	FilesHelper::getClients();

	for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
		clientIt->displayInfo();
	}


	
}

