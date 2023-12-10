#include "Label_File.h"
#include <format>
#include <iostream>
#include <vector>

DataBaseDesign::Label_File::Label_File()
    : label_file_key(0), label_key(0), file_key(0)
{
}

DataBaseDesign::Label_File::Label_File(char** argv)
    : label_file_key(std::stoll(argv[0])), label_key(std::stoll(argv[1])), file_key(std::stoll(argv[2]))
{
}

DataBaseDesign::Label_File::Label_File(const int64_t& label_key, const int64_t& file_key)
    : label_file_key(0), label_key(label_key), file_key(file_key)
{
}

DataBaseDesign::Label_File::Label_File(const int64_t& label_file_key, const int64_t& label_key, const int64_t& file_key)
    : label_file_key(label_file_key), label_key(label_key), file_key(file_key)
{
}

int DataBaseDesign::Label_File::callback(void* vector_pointer, int argc, char** argv, char** azColName)
{
    std::vector<DataBaseDesign::Label_File>* labels_files = reinterpret_cast<std::vector<DataBaseDesign::Label_File>*>(vector_pointer);
    labels_files->emplace_back(DataBaseDesign::Label_File(argv));
    auto& label_file = (*labels_files).back();
    std::cout << std::format("label_file_key: {}, label_key: {}\n", label_file.label_file_key, label_file.label_key);

    return 0;
}

std::string DataBaseDesign::Label_File::get_table_name()
{
    return std::string("LABEL_FILE");
}

std::string DataBaseDesign::Label_File::get_create_table_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_alter_table_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_drop_table_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_insert_record_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_select_record_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_update_record_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_delete_record_sql()
{
    return std::string();
}

std::string DataBaseDesign::Label_File::get_other_sql()
{
    return std::string();
}
