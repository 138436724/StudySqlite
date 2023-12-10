#include "SqliteHandle.h"
#include "TableDefinition/Suffix.h"
#include "TableDefinition/Label.h"
#include <filesystem>
#include <iostream>

int main()
{
	std::filesystem::path db_path("test.db");

	if (std::filesystem::exists(db_path))
	{
		std::filesystem::remove(db_path);
	}

	DataBaseDesign::SQLiteHandle handle{};
	if (!handle.Initialize(db_path.string()))
	{
		return -1;
	}

	DataBaseDesign::Suffix suffix{};

	if (!handle.CheckTabelExist(suffix))
	{
		handle.CreateTable<DataBaseDesign::Suffix>(suffix);
		std::vector<DataBaseDesign::Suffix> suffixes{
			DataBaseDesign::Suffix("png"),
			DataBaseDesign::Suffix("hdr"),
			DataBaseDesign::Suffix("jpg") };
		handle.InsertRecord<DataBaseDesign::Suffix>(suffixes);
	}

	std::vector<DataBaseDesign::Suffix> s = handle.SelectRecord<DataBaseDesign::Suffix>(suffix);

	for (auto& a : s)
	{
		std::cout << a.suffix_key << a.suffix_name << std::endl;
	}

	DataBaseDesign::Label label{};
	if (!handle.CheckTabelExist(label))
	{
		handle.CreateTable<DataBaseDesign::Label>(label);
		std::vector<DataBaseDesign::Label> labels{
			DataBaseDesign::Label("ͼƬ"),
			DataBaseDesign::Label("��Ƶ"),
			DataBaseDesign::Label("С˵") };
		handle.InsertRecord<DataBaseDesign::Label>(labels);
	}
	std::vector<DataBaseDesign::Label> l = handle.SelectRecord<DataBaseDesign::Label>(label);

	for (auto& a : l)
	{
		std::cout << a.label_key << a.label_name << std::endl;
	}

	return 0;
}
