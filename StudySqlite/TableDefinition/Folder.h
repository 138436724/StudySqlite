#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/************************************
	* ����Folder�����ƣ�
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.�ļ�������
	* 3.�ļ�������·��
	* 4.��·��������
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