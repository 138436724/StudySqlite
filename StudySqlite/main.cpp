#include "SqliteHandle.h"
#include <iostream>

int main()
{
	if (!MyDatabase::SQLiteHandle::Initialize())
	{
		return -1;
	}

	MyDatabase::SQLiteHandle::AddLabel()
	//int rc = sqlite3_open("test.db", &Database::SQLiteHandle::db);
	//if (rc) {
	//	sqlite3_close(Database::SQLiteHandle::db);
	//	return(1);

	//}


	return 0;
}
