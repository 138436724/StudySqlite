#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/***************************************************************
	* ����File������
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.�ļ�����
	* 3.�ļ�����·��
	* 4.�ļ��޸�ʱ�䣺ÿ�γ�ʼ���Ա��޸�ʱ�䣬���û�б仯����������Ⱦͼ��
	* 5.�ļ�Ԥ��ͼ(��ȷ����
	* 6.��·��������
	* 7.Suffix������
	***************************************************************/
	class File :public BaseTable
	{
	public:
		int64_t file_key;
		std::string file_name;
		std::string file_path;
		std::string modify_time;
		std::string file_image;//���� base64
		int64_t parent_key;
		int64_t suffix_key;
	};
}