#pragma once

#include "BaseTable.h"

namespace DataBaseDesign {
	/*************************************************
	* 关于Label与File关联表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.Label的主键
	* 3.File的主键
	* 说明：由于Label与File是 n 对 n 的关系，需要新表存储
	* n 对 1 的关系，在 n 表里面存 1 表的 key 就可以了
	* 1 对 1 关系可以存在一张表里面
	*************************************************/
	class Label_File :public BaseTable
	{
		int64_t label_file_key;
		int64_t	label_key;
		int64_t file_key;
	};
}