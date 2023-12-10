#include "SqliteHandle.h"
#include <string>

DataBaseDesign::SQLiteHandle::SQLiteHandle()
	:db(nullptr), zErrMsg(nullptr), rc(0), sql(nullptr)
{
}

DataBaseDesign::SQLiteHandle::~SQLiteHandle()
{
}

bool DataBaseDesign::SQLiteHandle::Initialize(const std::string& db_path)
{
	// 打开数据库
	int rc = sqlite3_open(db_path.c_str(), &db);
	if (rc != SQLITE_OK)
	{
		std::cout << std::format("Can't open database: %s", sqlite3_errmsg(db)) << std::endl;
		sqlite3_close(db);
		return false;
	}
	return true;
}

int DataBaseDesign::SQLiteHandle::CheckTabelExistCallback(void* bool_pointer, int argc, char** argv, char** azColName)
{
	bool* b = reinterpret_cast<bool*>(bool_pointer);
	(*b) = (std::stoll(argv[0]) > 0);
	return 0;
}
