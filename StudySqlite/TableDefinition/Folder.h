#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/************************************
	* 关于Folder表的设计：
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件夹名称
	* 3.文件夹完整路径
	* 4.父路径的主键
	************************************/
	class Folder :public BaseTable
	{
	public:
		int64_t folder_key;
		std::string folder_name;
		std::string folder_path;
		int64_t parent_key;
	};
}