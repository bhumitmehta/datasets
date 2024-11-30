#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <map>
#include <fmt/format.h>
#include "dataset/dataset.h"

namespace Dataset {

    // Constructor to initialize Dataset with file path and load the data
    Dataset::Dataset(const std::string& file_path) {
        load_dataset(file_path);
    }

    // Load dataset from CSV file
    void Dataset::load_dataset(const std::string& file_path) {
        std::ifstream fin(file_path);
        if (!fin.is_open()) {
            std::cerr << "Error: Could not open the file '" << file_path << "'!" << std::endl;
            return;
        }

        std::string line;
        bool isFirstLine = true;

        // Read the file line by line
        while (getline(fin, line)) {
            std::stringstream ss(line);
            std::string value;

            std::vector<std::string> row;
            if (isFirstLine) {
                // Extract header information (first row)
                while (getline(ss, value, ',')) {
                    headerMap[value] = headerMap.size(); // Create a map of column names to indices
                }
                isFirstLine = false;
            } else {
                // Extract data rows
                while (getline(ss, value, ',')) {
                    row.push_back(value);
                }
                data.push_back(row); // Add the row to the dataset
            }
        }

        fin.close();
    }

    // Print the top 'n' rows of the dataset
    void Dataset::head(int n) const {
        int count = 0;
        for (const auto& row : data) {
            if (count >= n) break;
            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
            count++;
        }
    }

    // Get a column's values by its name
    std::vector<std::string> Dataset::get_column(const std::string& column_name) const {
        std::vector<std::string> columnValues;
        int columnIndex = headerMap.at(column_name);  // Retrieve the column index using the header map
        for (const auto& row : data) {
            columnValues.push_back(row[columnIndex]);
        }
        return columnValues;
    }

    // Calculate the mean of a numeric column
    double Dataset::mean(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::vector<double> values;

        for (const auto& value : column) {
            try {
                values.push_back(std::stod(value)); // Convert to double for calculation
            } catch (const std::invalid_argument&) {
                continue; // Skip invalid numbers
            }
        }

        double sum = std::accumulate(values.begin(), values.end(), 0.0);
        return sum / values.size();
    }

    // Calculate the median of a numeric column
    double Dataset::median(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::vector<double> values;

        for (const auto& value : column) {
            try {
                values.push_back(std::stod(value)); // Convert to double for calculation
            } catch (const std::invalid_argument&) {
                continue; // Skip invalid numbers
            }
        }

        std::sort(values.begin(), values.end());

        size_t size = values.size();
        if (size % 2 == 0) {
            return (values[size / 2 - 1] + values[size / 2]) / 2.0;
        } else {
            return values[size / 2];
        }
    }

    // Calculate the mode of a column (most frequent value)
    std::string Dataset::mode(const std::string& column_name) const {
        std::vector<std::string> column = get_column(column_name);
        std::map<std::string, int> frequencyMap;

        for (const auto& value : column) {
            frequencyMap[value]++;
        }

        std::string modeValue;
        int maxCount = 0;
        for (const auto& pair : frequencyMap) {
            if (pair.second > maxCount) {
                modeValue = pair.first;
                maxCount = pair.second;
            }
        }
        return modeValue;
    }

    // Overloading operator[] to access columns by name
    std::vector<std::string> Dataset::operator[](const std::string& column_name) const {
        return get_column(column_name);
    }

    // Generating a localized greeting based on the language code
    std::string Dataset::dataset(LanguageCode lang) const {
        switch (lang) {
            default:
            case LanguageCode::EN:
                return "Hello, dataset!";
            case LanguageCode::DE:
                return "Hallo, dataset!";
            case LanguageCode::ES:
                return "¡Hola, dataset!";
            case LanguageCode::FR:
                return "Bonjour, dataset!";
        }
    }
}

