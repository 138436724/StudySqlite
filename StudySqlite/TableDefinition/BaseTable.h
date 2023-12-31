#pragma once

#include <string>

/**************************************************************
* 注意事项：
* 考虑到表设计的多样性，目前没有办法自动创建语句。
* 请开发者继承BaseTable，并在需要的时候自行填充语句。
* 务必提供一个参数为 char** argv 的构造函数，回调函数中将会调用它。
**************************************************************/
namespace DatabaseDesign {
	/*
	* 基础信息和SQL语句
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

		virtual std::string get_other_sql() = 0;// 非上述情况下使用的、自定义的语句，不推荐使用
	};
}