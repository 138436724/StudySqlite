#include "SqliteHandle.h"

namespace MyDataBase {
	SQLiteHandle::SQLiteHandle()
		:db(nullptr), table_names({})
	{
	}

	SQLiteHandle::~SQLiteHandle()
	{
		free(db);
		delete db;
		for (auto& table_name : table_names)
		{
			delete table_name;
		}
		delete[] table_names;
	}

	bool SQLiteHandle::Initialize()
	{
		// 打开数据库
		int rc = sqlite3_open("test.db", &db);
		if (rc != SQLITE_OK)
		{
			std::cout << std::format("Can't open database: %s", sqlite3_errmsg(db)) << std::endl;
			sqlite3_close(db);
			return false;
		}
	}

	bool SQLiteHandle::CreateTable()
	{
		// 查找表是否存在
		for (auto& table_name : table_names)
		{

		}
		sql = "SELECT * FROM sqlite_master WHERE type = 'table' and NAME = '%S'";
		sql = "CREATE TABLE COMPANY("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"NAME           TEXT    NOT NULL," \
			"AGE            INT     NOT NULL," \
			"ADDRESS        CHAR(50)," \
			"SALARY         REAL );";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Table created successfully\n");
		}
		sqlite3_close(db);


		return true;
		return false;
	}

	template<typename T>
	bool SQLiteHandle::AddRecord(std::vector<T> records)
	{
		for (const auto& record : records)
		{
			record.name = 1;
		}
		return false;
	}
}