#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/***************************************************************
	* 关于File表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件名称
	* 3.文件完整路径
	* 4.文件修改时间：每次初始化对比修改时间，如果没有变化，不重新渲染图像
	* 5.文件预览图(不确定）
	* 6.父路径的主键
	* 7.Suffix的主键
	***************************************************************/
	class File :public BaseTable
	{
	public:
		int64_t file_key;
		std::string file_name;
		std::string file_path;
		std::string modify_time;
		std::string file_image;//尝试 base64
		int64_t parent_key;
		int64_t suffix_key;

	public:
		File();
		File(char** argv);
		File(const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key);
		File(const int64_t& file_key, const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key);
		static int callback(void* vector_pointer, int argc, char** argv, char** azColName);

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