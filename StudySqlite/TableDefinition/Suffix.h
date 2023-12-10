#pragma once

#include "BaseTable.h"

/***************************************************************************************************************
* һЩ����˵����
* �����Ҫ����ǩ��ʾFile��Label����ô��������·�ʽ����ǩ��ָ����һЩSuffix�ļ��ϣ�ͨ��Suffix�����ļ���ͨ���ļ�����Label��
* Suffix����File�йأ�LabelҲ����File�йء�Suffix��Label�޹ء�
* Folder��File�йء�Label��Folder�޹ء�Ҳ����˵���޷���Ŀ¼���ǩ�����Ը�Ŀ¼�������е��ļ����ǩ��
***************************************************************************************************************/
namespace DataBaseDesign {
	/************************************
	* ����Suffix������
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.�ļ���׺��
	************************************/
	class Suffix :public BaseTable
	{
	public:
		int64_t suffix_key;
		std::string suffix_name;

	public:
		Suffix() = default;
		Suffix(const std::string& suffix_name);
		Suffix(const int64_t& suffix_key, const std::string& suffix_name);
		static int callback(void* suffixes, int argc, char** argv, char** azColName);

	public:
		// ͨ�� BaseSQLStatements �̳�
		std::string get_table_name() override final;
		std::string get_create_table_sql() override final;
		std::string get_alter_table_sql() override final;
		std::string get_drop_table_sql() override final;
		std::string get_insert_record_sql() override final;
		std::string get_select_record_sql() override final;
		std::string get_update_record_sql() override final;
		std::string get_delete_record_sql() override final;
		std::string get_other_sql() override final;
	};
}