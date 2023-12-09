#pragma once

#include "sqlite3.h"
#include <format>
#include <iostream>
#include <vector>

namespace DataBaseDesign
{
	// SQLite Handle
	class SQLiteHandle
	{
	public:
		SQLiteHandle();
		~SQLiteHandle();

	public:
		/************* 数据库操作 *************/
		// 1.数据库初始化
		bool Initialize(const std::string& db_path);

		////////////// 模板函数 //////////////
		// 2.表的建立
		template <typename T>
		bool CreateTable(T& table);

		// 3.Insert
		template <typename T>
		bool InsertRecord(T& table);

		template<typename T>
		bool InsertRecord(std::vector<T>& tables);

		// 3.增删改查
		template <typename T>
		std::vector<T> SelectRecord(T& table);//添加标签

	private:
		// 数据库相关
		sqlite3* db;
		char* zErrMsg;
		int  rc;
		char* sql;
	};


	/********************************
	* 非模板函数只支持分离编译，否则内联
	* 模板不支持分离编译，否则要显式声明
	********************************/
	template<typename T>
	bool SQLiteHandle::CreateTable(T& table)
	{
		rc = sqlite3_exec(db, table.get_create_table_sql().c_str(), nullptr, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			return false;
		}
		else {
			fprintf(stdout, "Table created successfully\n");
			return true;
		}
	}

	template<typename T>
	bool SQLiteHandle::InsertRecord(T& table)
	{
		rc = sqlite3_exec(db, table.get_insert_record_sql().c_str(), nullptr, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			return false;
		}
		else {
			fprintf(stdout, "Records created successfully\n");
			return true;
		}
	}

	template<typename T>
	bool SQLiteHandle::InsertRecord(std::vector<T>& tables)
	{
		for (auto& table : tables)
		{
			rc = sqlite3_exec(db, table.get_insert_record_sql().c_str(), nullptr, nullptr, &zErrMsg);
			if (rc != SQLITE_OK) {
				fprintf(stderr, "SQL error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
				return false;
			}
			else {
				fprintf(stdout, "Records created successfully\n");
				
			}
		}
		return true;
	}

	template<typename T>
	std::vector<T> SQLiteHandle::SelectRecord(T& table)
	{
		std::vector<T> tables{};
		rc = sqlite3_exec(db, table.get_select_record_sql().c_str(), table.callback, &tables, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}
		return tables;
	}
}