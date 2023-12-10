#pragma once

#include <string>

/***************************************************************************************************************
* ע�����
* ���ǵ�����ƵĶ����ԣ�Ŀǰû�а취�Զ�������䡣
* �뿪���߼̳�BaseTable��������Ҫ��ʱ�����������䡣
* ��������е�˳����������Ա����˳����ͬ���������ṩ���캯����
* �������������ʵ�� callback ����
***************************************************************************************************************/
namespace DataBaseDesign {
	/*
	* ������Ϣ��SQL���
	*/
	class BaseTable
	{
	public:
		virtual std::string get_table_name() = 0;

		virtual std::string get_create_table_sql() = 0;
		virtual std::string get_alter_table_sql() = 0;
		virtual std::string get_drop_table_sql() = 0;

		virtual std::string get_insert_record_sql() = 0;
		virtual std::string get_select_record_sql() = 0;
		virtual std::string get_update_record_sql() = 0;
		virtual std::string get_delete_record_sql() = 0;

		virtual std::string get_other_sql() = 0;// �����������ʹ�õġ��Զ������䣬���Ƽ�ʹ��
	};
}