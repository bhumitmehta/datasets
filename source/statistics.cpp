#include "dataset.h"
#include "statistics.h"
#include <stdexcept>
#include "statistics.h"
#include<map>

namespace Dataset {

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
        
        std::sort(numeric_values.begin(),numeric_values.end());

        size_t size = numeric_values.size();

        if (size % 2 == 0) {
            return (numeric_values[size / 2 - 1] + numeric_values[size / 2]) / 2.0;
        } else {
            return numeric_values[size / 2];
        }
     }

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
}


