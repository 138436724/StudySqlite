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
		/************* ���ݿ���� *************/
		// Open
		bool Initialize(const std::string& db_path);

		////////////// ģ�庯�� //////////////
		// Check
		template <typename T>
		bool CheckTabelExist(T& table);

		// Create
		template <typename T>
		bool CreateTable(T& table);

		// Insert
		template <typename T>
		bool InsertRecord(T& table);

		template<typename T>
		bool InsertRecord(std::vector<T>& tables);

		// Select
		template <typename T>
		std::vector<T> SelectRecord(T& table);

		// Close
		
		/************* callback *************/
		static int CheckTabelExistCallback(void* bool_pointer, int argc, char** argv, char** azColName);

		template <typename T>
		static int SelectCallback(void* vector_pointer, int argc, char** argv, char** azColName);


	private:
		// ���ݿ����
		sqlite3* db;
		char* zErrMsg;
		int  rc;
		char* sql;
	};


	/********************************
	* ��ģ�庯��ֻ֧�ַ�����룬��������
	* ģ�岻֧�ַ�����룬����Ҫ��ʽ����
	********************************/
	template<typename T>
	bool DataBaseDesign::SQLiteHandle::CheckTabelExist(T& table)
	{
		std::string s = std::format("SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='{}';", table.get_table_name());
		bool is_exist;
		rc = sqlite3_exec(db, s.c_str(), SQLiteHandle::CheckTabelExistCallback, &is_exist, &zErrMsg);

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

	template<typename T>
	bool SQLiteHandle::CreateTable(T& table)
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

	template<typename T>
	bool SQLiteHandle::InsertRecord(T& table)
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
	bool SQLiteHandle::InsertRecord(std::vector<T>& tables)
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

	template<typename T>
	std::vector<T> SQLiteHandle::SelectRecord(T& table)
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

	template<typename T>
	int DataBaseDesign::SQLiteHandle::SelectCallback(void* vector_pointer, int argc, char** argv, char** azColName)
	{
		std::vector<T>* vectors = reinterpret_cast<std::vector<T>*>(vector_pointer);
		vectors->emplace_back(T(argv));
		auto& v = (*vectors).back();
		v;
		return 0;
	}
}