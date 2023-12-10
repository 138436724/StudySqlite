#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/************************************
	* ����Label�����ƣ�
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.���ƣ��û������Label
	************************************/
	class Label :public BaseTable
	{
	public:
		int64_t label_key;
		std::string label_name;
	
	public:
		Label();
		Label(char** argv);
		Label(const std::string& label_name);
		Label(const int64_t& label_key, const std::string& label_name);
	
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