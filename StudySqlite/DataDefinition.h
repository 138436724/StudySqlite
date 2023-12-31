#pragma once

#include <string>

/***************************************************************************************************************
* 一些其他说明：
* 如果需要按标签显示File和Label，那么请采用如下方式：标签是指定的一些Suffix的集合，通过Suffix搜索文件，通过文件搜索Label。
* Suffix仅与File有关，Label也仅与File有关。Suffix与Label无关。
* Folder与File有关。Label与Folder无关。也就是说，无法给目录打标签，可以给目录下面所有的文件打标签。
***************************************************************************************************************/
namespace MyDataBase {
	/************************************
	* 关于Suffix表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件后缀名
	************************************/
	struct Suffix
	{
		int64_t suffix_key;
		std::string suffix;
	};

	/************************************
	* 关于Label表的设计：
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.名称：用户定义的Label
	************************************/
	struct Label
	{
		int64_t label_key;
		std::string label_name;
	};

	/************************************
	* 关于Folder表的设计：
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件夹名称
	* 3.文件夹完整路径
	* 4.父路径的主键
	************************************/
	struct Folder
	{
		int64_t folder_key;
		std::string folder_name;
		std::string folder_path;
		int64_t parent_key;
	};

	/***************************************************************
	* 关于File表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.文件名称
	* 3.文件完整路径
	* 4.文件修改时间：每次初始化对比修改时间，如果没有变化，不重新渲染图像
	* 5.文件预览图(不确定）
	* 6.父路径的主键
	* 7.Suffix的主键
	***************************************************************/
	struct File
	{
		int64_t file_key;
		std::string file_name;
		std::string file_path;
		std::string modify_time;
		std::string file_image;//尝试 base64
		int64_t parent_key;
		int64_t suffix_key;
	};

	/*************************************************
	* 关于Label与File关联表的设计
	* 1.主键：自增的，唯一标识，由数据库生成
	* 2.Label的主键
	* 3.File的主键
	* 说明：由于Label与File是 n 对 n 的关系，需要新表存储
	* n 对 1 的关系，在 n 表里面存 1 表的 key 就可以了
	* 1 对 1 关系可以存在一张表里面
	*************************************************/
	struct Label_File
	{
		int64_t label_file_key;
		int64_t	label_key;
		int64_t file_key;
	};
}