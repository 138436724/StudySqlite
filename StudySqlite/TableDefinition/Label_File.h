#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/*************************************************
	* ����Label��File����������
	* 1.�����������ģ�Ψһ��ʶ�������ݿ�����
	* 2.Label������
	* 3.File������
	* ˵��������Label��File�� n �� n �Ĺ�ϵ����Ҫ�±�洢
	* n �� 1 �Ĺ�ϵ���� n ������� 1 ��� key �Ϳ�����
	* 1 �� 1 ��ϵ���Դ���һ�ű�����
	*************************************************/
	class Label_File :public BaseTable
	{
		int64_t label_file_key;
		int64_t	label_key;
		int64_t file_key;
	};
}