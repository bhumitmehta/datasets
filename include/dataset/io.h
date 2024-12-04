#pragma once

#include <string>

namespace Dataset {
    

    /**
     * @brief Function to load dataset from a CSV file
     * @param file_path Path to the CSV file
     */
    void load_dataset(const std::string& file_path);
    
    /**
     * @brief Function to save the data in Csv file
     * @param file_path Path to the output CSV file
     */
    void save(const std::string& file_path);
}
