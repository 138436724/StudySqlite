#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/************************************
	* 关于Label表的设计：
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.名称：用户定义的Label
	************************************/
	class Label :public BaseTable
	{
		int64_t label_key;
		std::string label_name;

		int callback(void* NotUsed, int argc, char** argv, char** azColName)
		{
			label_key = std::stoll(azColName[0]);
			label_name = azColName[1];
			/*int i;
			for (i = 0; i < argc; i++) {
				printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			}
			printf("\n");*/
			return 0;
		}
	};
}