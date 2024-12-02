#include "io.h"
#include "dataset.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Dataset {

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

            if (is_first_line) {
                // Parse headers
                while (getline(ss, value, ',')) {
                    headers.push_back(value);
                    data[value] = {}; // Initialize empty column
                }
                is_first_line = false;
            } else {
                // Parse rows
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


    void Dataset::save(const std::string& file_path) {
    // Open file in output mode
    std::ofstream file(file_path, std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open the file '" + file_path + "'!");
    }

    // Write headers
    for (size_t j = 0; j < headers.size(); ++j) {
        file << headers[j];
        if (j < headers.size() - 1) {
            file << ","; // Add a comma between headers
        }
    }
    file << std::endl;

    // Get the number of rows
    size_t num_rows = data[headers[0]].size();

    // Write data rows
    for (size_t i = 0; i < num_rows; ++i) {
        for (size_t j = 0; j < headers.size(); ++j) {
            file << data[headers[j]][i];
            if (j < headers.size() - 1) {
                file << ","; // Add a comma between values
            }
        }
        file << std::endl;
    }

    

    // Close file
    file.close();
}

}
