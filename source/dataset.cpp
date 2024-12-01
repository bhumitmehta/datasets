#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include "dataset/dataset.h"


namespace Dataset {

    // Constructor to initialize Dataset with file path and load the data
    Dataset::Dataset(const std::string& file_path) {
        load_dataset(file_path);
    }

    // Load dataset from a CSV file
    void Dataset::load_dataset(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open the file '" + file_path + "'!");
        }

        std::string line;
        bool is_first_line = true;

        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string value;
            std::vector<std::string> row;

            if (is_first_line) {
                // Read headers
                while (getline(ss, value, ',')) {
                    headers.push_back(value);
                    data[value] = {}; // Initialize empty column data
                }
                is_first_line = false;
            } else {
                // Read row data
                int col_index = 0;
                while (getline(ss, value, ',')) {
                    if (col_index < headers.size()) {
                        data[headers[col_index]].push_back(value);
                    }
                    ++col_index;
                }
            }
        }
        file.close();
    }

    // Print the top 'n' rows of the dataset
    void Dataset::head(int n) const {
        if (headers.empty()) {
            std::cerr << "Dataset is empty!" << std::endl;
            return;
        }

        // Print headers
        for (const auto& header : headers) {
            std::cout << header << "\t";
        }
        std::cout << std::endl;

        // Print rows
        for (size_t i = 0; i < n && i < data.at(headers[0]).size(); ++i) {
            for (const auto& header : headers) {
                std::cout << data.at(header)[i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    // Get values from a column by name
    std::vector<std::string> Dataset::get_column(const std::string& column_name) const {
        auto it = data.find(column_name);
        if (it == data.end()) {
            throw std::invalid_argument("Column not found: " + column_name);
        }
        return it->second;
    }

    // Add a new column to the dataset
    void Dataset::add_column(const std::string& column_name, const std::vector<std::string>& values) {
        if (data.find(column_name) != data.end()) {
            throw std::invalid_argument("Column already exists: " + column_name);
        }

        if (!headers.empty() && values.size() != data[headers[0]].size()) {
            throw std::invalid_argument("Column length does not match existing dataset rows.");
        }

        headers.push_back(column_name);
        data[column_name] = values;
    }

    // Calculate the mean of a numeric column
    double Dataset::mean(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::vector<double> numeric_values;

        for (const auto& value : column) {
            try {
                numeric_values.push_back(std::stod(value));
            } catch (const std::invalid_argument&) {
                // Ignore non-numeric entries
            }
        }

        if (numeric_values.empty()) {
            throw std::runtime_error("No numeric data found in column: " + column_name);
        }

        double sum = std::accumulate(numeric_values.begin(), numeric_values.end(), 0.0);
        return sum / numeric_values.size();
    }

    // Calculate the median of a numeric column
    double Dataset::median(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::vector<double> numeric_values;

        for (const auto& value : column) {
            try {
                numeric_values.push_back(std::stod(value));
            } catch (const std::invalid_argument&) {
                // Ignore non-numeric entries
            }
        }

        if (numeric_values.empty()) {
            throw std::runtime_error("No numeric data found in column: " + column_name);
        }

        std::sort(numeric_values.begin(), numeric_values.end());
        size_t size = numeric_values.size();
        if (size % 2 == 0) {
            return (numeric_values[size / 2 - 1] + numeric_values[size / 2]) / 2.0;
        } else {
            return numeric_values[size / 2];
        }
    }

    // Calculate the mode of a column
    std::string Dataset::mode(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::map<std::string, int> frequency_map;

        for (const auto& value : column) {
            frequency_map[value]++;
        }

        std::string mode_value;
        int max_count = 0;
        for (const auto& pair : frequency_map) {
            if (pair.second > max_count) {
                mode_value = pair.first;
                max_count = pair.second;
            }
        }
        return mode_value;
    }

    // Overload operator[] to access columns by name
    std::vector<std::string> Dataset::operator[](const std::string& column_name) const {
        return get_column(column_name);
    }

    // Generate a localized greeting based on language code
    std::string Dataset::dataset(LanguageCode lang) const {
        switch (lang) {
            case LanguageCode::DE: return "Hallo, dataset!";
            case LanguageCode::ES: return "¡Hola, dataset!";
            case LanguageCode::FR: return "Bonjour, dataset!";
            default: return "Hello, dataset!";
        }
    }

} // namespace Dataset
