#include "dataset.h"
#include <iostream>
#include <stdexcept>

namespace Dataset {

    // Constructor
    Dataset::Dataset(const std::string& file_path) {
        load_dataset(file_path);
    }

    void Dataset::head(int n) const {
        if (headers.empty()) {
            std::cout << "Dataset is empty!" << std::endl;
            return;
        }

        // Print headers
        for (const auto& header : headers) {
            std::cout << header << "\t";
        }
        std::cout << std::endl;

        // Print rows
        for (int i = 0; i < n && i < data.begin()->second.size(); ++i) {
            for (const auto& header : headers) {
                std::cout << data.at(header)[i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::string> Dataset::get_column(const std::string& column_name) const {
        if (data.find(column_name) == data.end()) {
            throw std::runtime_error("Column '" + column_name + "' not found!");
        }
        return data.at(column_name);
    }

    void Dataset::add_column(const std::string& column_name, const std::vector<std::string>& values) {
        if (data.find(column_name) != data.end()) {
            throw std::runtime_error("Column '" + column_name + "' already exists!");
        }
        if (!data.empty() && values.size() != data.begin()->second.size()) {
            throw std::runtime_error("New column must have the same number of rows as existing columns!");
        }

        headers.push_back(column_name);
        data[column_name] = values;
        }
} // namespace Dataset
