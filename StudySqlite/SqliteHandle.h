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
		/*********** ���ݿ���� ***********/
		// 1.���ݿ��ʼ��
		bool Initialize();
		// 2.��Ľ���
		bool CreateTable();
		// 3.��ɾ�Ĳ�
		template <typename T>
		bool AddRecord(std::vector<T> records);//��ӱ�ǩ


	private:
		// ���ݿ����
		sqlite3* db = nullptr;
		char* zErrMsg = 0;
		int  rc;
		char* sql;

		// �����
		std::vector<std::string> table_names;




	};
}