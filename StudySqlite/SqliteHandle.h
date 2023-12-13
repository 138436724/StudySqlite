#pragma once

#include "sqlite3.h"
#include <format>
#include <iostream>
#include <vector>
#include <string>

namespace DatabaseDesign
{
	// SQLite Handle
	class SQLiteHandle
	{
	public:
		SQLiteHandle() :db(nullptr), zErrMsg(nullptr), rc(0), sql(nullptr) {}
		~SQLiteHandle() {}

	public:
		/******************************************* Open DB *******************************************/
		bool Initialize(const std::string& db_path)
		{
			rc = sqlite3_open(db_path.c_str(), &db);
			if (rc != SQLITE_OK)
			{
				std::cout << std::format("Can't open database: %s", sqlite3_errmsg(db)) << std::endl;
				sqlite3_close(db);
				return false;
			}
			return true;
		}

		/******************************************* Close DB *******************************************/
		bool CloseDatabase()
		{
			rc =sqlite3_close(db);
			if (rc != SQLITE_OK)
			{
				std::cout << std::format("Can't close database: %s", sqlite3_errmsg(db)) << std::endl;
				sqlite3_close(db);
				return false;
			}
			return true;
		}

		/******************************************* Check Table *******************************************/
		template <typename T>
		bool CheckTabelExist(T& table) 
		{
			std::string s = std::format("SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='{}';", table.get_table_name());
			bool is_exist;
			rc = sqlite3_exec(db, s.c_str(), SQLiteHandle::CheckTableExistCallback, &is_exist, &zErrMsg);

			if (rc != SQLITE_OK) {
				fprintf(stderr, "SQL error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
				return false;
			}
			else {
				if (is_exist)
				{
					fprintf(stdout, "Table Exist\n");
					return true;
				}
				return false;
			}
		}

		static int CheckTableExistCallback(void* bool_pointer, int argc, char** argv, char** azColName)
		{
			bool* b = reinterpret_cast<bool*>(bool_pointer);
			(*b) = (std::stoll(argv[0]) > 0);
			return 0;
		}

		/******************************************* Create Table *******************************************/
		template <typename T>
		bool CreateTable(T& table)
		{
			rc = sqlite3_exec(db, table.get_create_table_sql().c_str(), nullptr, nullptr, &zErrMsg);
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

		/******************************************* Insert Record *******************************************/
		template <typename T>
		bool InsertRecord(T& table)
		{
			rc = sqlite3_exec(db, table.get_insert_record_sql().c_str(), nullptr, nullptr, &zErrMsg);
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
		bool InsertRecord(std::vector<T>& tables)
		{
			std::string s = "";
			for (auto& table : tables)
			{
				s += table.get_insert_record_sql();

			}
			rc = sqlite3_exec(db, s.c_str(), nullptr, nullptr, &zErrMsg);
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

		/******************************************* Select Record *******************************************/
		template <typename T>
		std::vector<T> SelectRecord(T& table)
		{
			std::vector<T> tables{};
			rc = sqlite3_exec(db, table.get_select_record_sql().c_str(), SQLiteHandle::SelectCallback<T>, &tables, &zErrMsg);
			if (rc != SQLITE_OK) {
				fprintf(stderr, "SQL error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
			}
			else {
				fprintf(stdout, "Operation done successfully\n");
			}
			return tables;
		}

		template <typename T>
		static int SelectCallback(void* vector_pointer, int argc, char** argv, char** azColName)
		{
			std::vector<T>* vectors = reinterpret_cast<std::vector<T>*>(vector_pointer);
			vectors->emplace_back(T(argv));
			auto& v = (*vectors).back();
			v;
			return 0;
		}

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
}