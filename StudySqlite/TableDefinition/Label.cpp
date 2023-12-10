#include "Label.h"
#include <format>
#include <iostream>
#include <vector>

DataBaseDesign::Label::Label()
	: label_key(0), label_name("")
{
}

DataBaseDesign::Label::Label(char** argv)
	: label_key(std::stoll(argv[0])), label_name(argv[1])
{
}

DataBaseDesign::Label::Label(const std::string& label_name)
	: label_key(0), label_name(label_name)
{
}

DataBaseDesign::Label::Label(const int64_t& label_key, const std::string& label_name)
	: label_key(label_key), label_name(label_name)
{
}

std::string DataBaseDesign::Label::get_table_name()
{
	return std::string("LABEL");
}

std::string DataBaseDesign::Label::get_create_table_sql()
{
	return std::format(
		"CREATE TABLE {} ("  \
		"label_key INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"    \
		"label_name TEXT NOT NULL);", get_table_name());
}

std::string DataBaseDesign::Label::get_alter_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Label::get_drop_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::Label::get_insert_record_sql()
{
	return std::format(
		"INSERT INTO {} (label_name)"  \
		"VALUES ('{}'); ", get_table_name(), label_name);
}

std::string DataBaseDesign::Label::get_select_record_sql()
{
	return std::string(std::format("SELECT * from {}", get_table_name()));
}

std::string DataBaseDesign::Label::get_update_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Label::get_delete_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::Label::get_other_sql()
{
	return std::string();
}
