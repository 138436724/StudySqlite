#pragma once

#include "BaseTable.h"

/***************************************************************************************************************
* 一些其他说明：
* 如果需要按标签显示File和Label，那么请采用如下方式：标签是指定的一些Suffix的集合，通过Suffix搜索文件，通过文件搜索Label。
* Suffix仅与File有关，Label也仅与File有关。Suffix与Label无关。
* Folder与File有关。Label与Folder无关。也就是说，无法给目录打标签，可以给目录下面所有的文件打标签。
***************************************************************************************************************/
namespace DatabaseDesign {
	/************************************
	* 关于Suffix表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件后缀名
	************************************/
	class Suffix final :public BaseTable
	{
	public:
		int64_t suffix_key;
		std::string suffix_name;

	public:
		Suffix();
		Suffix(char** argv);
		Suffix(const std::string& suffix_name);
		Suffix(const int64_t& suffix_key, const std::string& suffix_name);

	public:
		// 通过 BaseSQLStatements 继承
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