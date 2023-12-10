#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/*************************************************
	* ����Label��File����������
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.Label������
	* 3.File������
	* ˵��������Label��File�� n �� n �Ĺ�ϵ����Ҫ�±�洢
	* n �� 1 �Ĺ�ϵ���� n ������� 1 ��� key �Ϳ�����
	* 1 �� 1 ��ϵ���Դ���һ�ű�����
	*************************************************/
	class Label_File :public BaseTable
	{
	public:
		int64_t label_file_key;
		int64_t	label_key;
		int64_t file_key;

	public:
		Label_File();
		Label_File(char** argv);
		Label_File(const int64_t& label_key, const int64_t& file_key);
		Label_File(const int64_t& label_file_key, const int64_t& label_key, const int64_t& file_key);
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