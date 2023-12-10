#include "File.h"
#include <format>
#include <iostream>
#include <vector>

DataBaseDesign::File::File()
	: file_key(0), file_name(""), file_path(""), modify_time(""), file_image(""), parent_key(0), suffix_key(0)

{
}

DataBaseDesign::File::File(char** argv)
	: file_key(std::stoll(argv[0])), file_name(argv[1]), file_path(argv[2]), modify_time(argv[3]), file_image(argv[4]), parent_key(std::stoll(argv[5])), suffix_key(std::stoll(argv[6]))
{
}

DataBaseDesign::File::File(const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key)
	: file_key(0), file_name(file_name), file_path(file_path), modify_time(modify_time), file_image(file_image), parent_key(parent_key), suffix_key(suffix_key)

{
}

DataBaseDesign::File::File(const int64_t& file_key, const std::string& file_name, const std::string& file_path, const std::string& modify_time, const std::string& file_image, const int64_t& parent_key, const int64_t& suffix_key)
	: file_key(file_key), file_name(file_name), file_path(file_path), modify_time(modify_time), file_image(file_image), parent_key(parent_key), suffix_key(suffix_key)
{
}

int DataBaseDesign::File::callback(void* vector_pointer, int argc, char** argv, char** azColName)
{
	std::vector<DataBaseDesign::File>* files = reinterpret_cast<std::vector<DataBaseDesign::File>*>(vector_pointer);
	files->emplace_back(DataBaseDesign::File(argv));
	auto& file = (*files).back();
	std::cout << std::format("file_key: {}, file_name: {}\n", file.file_key, file.file_name);

	return 0;
}

std::string DataBaseDesign::File::get_table_name()
{
	return std::string("FILE");
}

std::string DataBaseDesign::File::get_create_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_alter_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_drop_table_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_insert_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_select_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_update_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_delete_record_sql()
{
	return std::string();
}

std::string DataBaseDesign::File::get_other_sql()
{
	return std::string();
}
