#include "Label_File.h"
#include <format>
#include <iostream>
#include <vector>

DatabaseDesign::Label_File::Label_File()
    : label_file_key(0), label_key(0), file_key(0)
{
}

DatabaseDesign::Label_File::Label_File(char** argv)
    : label_file_key(std::stoll(argv[0])), label_key(std::stoll(argv[1])), file_key(std::stoll(argv[2]))
{
}

DatabaseDesign::Label_File::Label_File(const int64_t& label_key, const int64_t& file_key)
    : label_file_key(0), label_key(label_key), file_key(file_key)
{
}

DatabaseDesign::Label_File::Label_File(const int64_t& label_file_key, const int64_t& label_key, const int64_t& file_key)
    : label_file_key(label_file_key), label_key(label_key), file_key(file_key)
{
}

std::string DatabaseDesign::Label_File::get_table_name()
{
    return std::string("LABEL_FILE");
}

std::string DatabaseDesign::Label_File::get_create_table_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_alter_table_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_drop_table_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_insert_record_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_select_record_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_update_record_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_delete_record_sql()
{
    return std::string();
}

std::string DatabaseDesign::Label_File::get_other_sql()
{
    return std::string();
}
