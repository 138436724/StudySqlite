#include "File.h"
#include <format>
#include <iostream>
#include <vector>

DatabaseDesign::File::File()
	: file_key(0), file_name(""), file_path(""), modify_time(""), file_image(""), parent_key(0), suffix_key(0)

{
}

DatabaseDesign::File::File(char** argv)
	: file_key(std::stoll(argv[0])), file_name(argv[1]), file_path(argv[2]), modify_time(argv[3]), file_image(argv[4]), parent_key(std::stoll(argv[5])), suffix_key(std::stoll(argv[6]))
{
}

DatabaseDesign::File::File(const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key)
	: file_key(0), file_name(file_name), file_path(file_path), modify_time(modify_time), file_image(file_image), parent_key(parent_key), suffix_key(suffix_key)

{
}

DatabaseDesign::File::File(const int64_t& file_key, const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key)
	: file_key(file_key), file_name(file_name), file_path(file_path), modify_time(modify_time), file_image(file_image), parent_key(parent_key), suffix_key(suffix_key)
{
}

std::string DatabaseDesign::File::get_table_name()
{
	return std::string("FILE");
}

std::string DatabaseDesign::File::get_create_table_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_alter_table_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_drop_table_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_insert_record_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_select_record_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_update_record_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_delete_record_sql()
{
	return std::string();
}

std::string DatabaseDesign::File::get_other_sql()
{
	return std::string();
}
