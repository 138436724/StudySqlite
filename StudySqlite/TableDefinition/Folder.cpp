#include "Folder.h"
#include <format>
#include <iostream>
#include <vector>

DataBaseDesign::Folder::Folder()
	: folder_key(0), folder_name(""), folder_path(""), parent_key(0)

{
}

DataBaseDesign::Folder::Folder(char** argv)
	: folder_key(std::stoll(argv[0])), folder_name(argv[1]), folder_path(argv[2]), parent_key(std::stoll(argv[3]))
{
}

DataBaseDesign::Folder::Folder(const std::string& folder_name, const std::string& folder_path, const int64_t& parent_key)
	: folder_key(0), folder_name(folder_name), folder_path(folder_path), parent_key(parent_key)

{
}

DataBaseDesign::Folder::Folder(const int64_t& folder_key, const std::string& folder_name, const std::string& folder_path, const int64_t& parent_key)
	: folder_key(folder_key), folder_name(folder_name), folder_path(folder_path), parent_key(parent_key)
{
}

std::string DataBaseDesign::Folder::get_table_name()
{
	return std::string("FOLDER");
}

std::string DataBaseDesign::Folder::get_create_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_alter_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_drop_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_insert_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_select_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_update_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_delete_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Folder::get_other_sql()
{
	return std::string();
}
