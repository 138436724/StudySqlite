#include "SqliteHandle.h"
#include "TableDefinition/Suffix.h"
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
	handle.CreateTable<DataBaseDesign::Suffix>(suffix);


	std::vector<DataBaseDesign::Suffix> suffixes{
	DataBaseDesign::Suffix(".exe"),
	DataBaseDesign::Suffix(".txt"),
	DataBaseDesign::Suffix(".rar") };
	handle.InsertRecord<DataBaseDesign::Suffix>(suffixes);

	std::vector<DataBaseDesign::Suffix> s = std::move( handle.SelectRecord<DataBaseDesign::Suffix>(suffix));

	return 0;
}
