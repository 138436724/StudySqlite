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