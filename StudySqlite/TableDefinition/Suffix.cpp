#include "Suffix.h"
#include <format>
#include <iostream>
#include <vector>

DataBaseDesign::Suffix::Suffix()
	: suffix_key(0), suffix_name("")
{
}

DataBaseDesign::Suffix::Suffix(char** argv)
	: suffix_key(std::stoll(argv[0])), suffix_name(argv[1])
{
}

DataBaseDesign::Suffix::Suffix(const std::string& suffix_name)
	: suffix_key(0), suffix_name(suffix_name)
{
}

DataBaseDesign::Suffix::Suffix(const int64_t& suffix_key, const std::string& suffix_name)
	: suffix_key(suffix_key), suffix_name(suffix_name)
{
}

std::string DataBaseDesign::Suffix::get_table_name()
{
	return std::string("SUFFIX");
}

std::string DataBaseDesign::Suffix::get_create_table_sql()
{
	return std::format(
		"CREATE TABLE {} ("  \
		"suffix_key INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"    \
		"suffix_name TEXT NOT NULL);", get_table_name());
}

std::string DataBaseDesign::Suffix::get_alter_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Suffix::get_drop_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Suffix::get_insert_record_sql()
{
	return std::format(
		"INSERT INTO {} (suffix_name)"  \
		"VALUES ('{}'); ", get_table_name(), suffix_name);
}

std::string DataBaseDesign::Suffix::get_select_record_sql()
{
	return std::string(std::format("SELECT * from {}", get_table_name()));
}

std::string DataBaseDesign::Suffix::get_update_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Suffix::get_delete_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Suffix::get_other_sql()
{
	return std::string();
}
