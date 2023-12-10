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
		// 1.���ݿ��ʼ��
		bool Initialize(const std::string& db_path);

		////////////// ģ�庯�� //////////////
		// 2.��Ľ���
		template <typename T>
		bool CreateTable(T& table);

		// 3.Insert
		template <typename T>
		bool InsertRecord(T& table);

		template<typename T>
		bool InsertRecord(std::vector<T>& tables);

		// 3.��ɾ�Ĳ�
		template <typename T>
		std::vector<T> SelectRecord(T& table);//��ӱ�ǩ

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