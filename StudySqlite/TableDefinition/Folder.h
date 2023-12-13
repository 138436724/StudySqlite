#pragma once

#include "BaseTable.h"

namespace DatabaseDesign {
	/************************************
	* 关于Folder表的设计：
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件夹名称
	* 3.文件夹完整路径
	* 4.父路径的主键
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
		// 通过 BaseTable 继承
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