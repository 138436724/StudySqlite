#include "SqliteHandle.h"
#include "TableDefinition/Suffix.h"
#include "TableDefinition/Label.h"
#include <filesystem>
#include <iostream>

int main()
{
	std::filesystem::path p("C:/Users/22685/Desktop/Language/C++/StudySqlite/StudySqlite/TableDefinition");
	std::cout << "根目录:" << p.root_directory() << std::endl;
	std::cout << "根目录:" << p.root_name() << std::endl;
	std::cout << "根目录:" << p.root_path() << std::endl;
	std::cout << "不带扩展的文件名:" << p.stem() << std::endl;
	std::cout << "扩展名:" << p.extension() << std::endl;
	std::cout << "文件名:" << p.filename() << std::endl;
	std::cout << "相对目录:" << p.relative_path() << std::endl;
	std::cout << "父目录:" << p.parent_path() << std::endl;


	std::filesystem::path db_path("test.db");

	if (std::filesystem::exists(db_path))
	{
		//std::filesystem::remove(db_path);
	}

	DatabaseDesign::SQLiteHandle handle{};
	if (!handle.Initialize(db_path.string()))
	{
		return -1;
	}

	DatabaseDesign::Suffix suffix{};

	if (!handle.CheckTabelExist(suffix))
	{
		handle.CreateTable<DatabaseDesign::Suffix>(suffix);
		std::vector<DatabaseDesign::Suffix> suffixes{
			DatabaseDesign::Suffix("png"),
			DatabaseDesign::Suffix("hdr"),
			DatabaseDesign::Suffix("jpg") };
		handle.InsertRecord<DatabaseDesign::Suffix>(suffixes);
	}

	std::vector<DatabaseDesign::Suffix> s = handle.SelectRecord<DatabaseDesign::Suffix>(suffix);

	for (auto& a : s)
	{
		std::cout << a.suffix_key << a.suffix_name << std::endl;
	}

	DatabaseDesign::Label label{};
	if (!handle.CheckTabelExist(label))
	{
		handle.CreateTable<DatabaseDesign::Label>(label);
		std::vector<DatabaseDesign::Label> labels{
			DatabaseDesign::Label("图片"),
			DatabaseDesign::Label("视频"),
			DatabaseDesign::Label("小说") };
		handle.InsertRecord<DatabaseDesign::Label>(labels);
	}
	std::vector<DatabaseDesign::Label> l = handle.SelectRecord<DatabaseDesign::Label>(label);

	for (auto& a : l)
	{
		std::cout << a.label_key << a.label_name << std::endl;
	}

	return 0;
}
