#pragma once

#include "DataDefinition.h"

#include <filesystem>
#include <iostream>
#include <vector>

#include "sqlite3.h"

namespace MyDataBase
{
	// SQLite Handle
	class SQLiteHandle
	{
	public:
		SQLiteHandle();
		~SQLiteHandle();

	public:
		/*********** 数据库操作 ***********/
		// 1.数据库初始化
		bool Initialize();
		// 2.表的建立
		bool CreateTable();
		// 3.增删改查
		template <typename T>
		bool AddRecord(std::vector<T> records);//添加标签


	private:
		// 数据库相关
		sqlite3* db = nullptr;
		char* zErrMsg = 0;
		int  rc;
		char* sql;

		// 表相关
		std::vector<std::string> table_names;




	};
}