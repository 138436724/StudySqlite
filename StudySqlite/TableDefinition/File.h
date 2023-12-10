#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/***************************************************************
	* ����File������
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.�ļ�����
	* 3.�ļ�����·��
	* 4.�ļ��޸�ʱ�䣺ÿ�γ�ʼ���Ա��޸�ʱ�䣬���û�б仯����������Ⱦͼ��
	* 5.�ļ�Ԥ��ͼ(��ȷ����
	* 6.��·��������
	* 7.Suffix������
	***************************************************************/
	class File :public BaseTable
	{
	public:
		int64_t file_key;
		std::string file_name;
		std::string file_path;
		std::string modify_time;
		std::string file_image;//���� base64
		int64_t parent_key;
		int64_t suffix_key;

	public:
		File();
		File(char** argv);
		File(const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key);
		File(const int64_t& file_key, const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key);
		static int callback(void* vector_pointer, int argc, char** argv, char** azColName);

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