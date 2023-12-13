#pragma once

#include "BaseTable.h"

namespace DatabaseDesign {
	/************************************
	* ����Folder�����ƣ�
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.�ļ�������
	* 3.�ļ�������·��
	* 4.��·��������
	************************************/
	class Folder final :public BaseTable
	{
	public:
		int64_t folder_key;
		std::string folder_name;
		std::string folder_path;
		int64_t parent_key;

	public:
		Folder();
		Folder(char** argv);
		Folder(const std::string& folder_name, const std::string& folder_path, const int64_t& parent_key);
		Folder(const int64_t& folder_key, const std::string& folder_name, const std::string& folder_path, const int64_t& parent_key);

	public:
		// ͨ�� BaseTable �̳�
		std::string get_table_name() override;
		std::string get_create_table_sql() override;
		std::string get_alter_table_sql() override;
		std::string get_drop_table_sql() override;
		std::string get_insert_record_sql() override;
		std::string get_select_record_sql() override;
		std::string get_update_record_sql() override;
		std::string get_delete_record_sql() override;
		std::string get_other_sql() override;
	};
}