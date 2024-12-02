#include "dataset.h"
#include <iostream>
#include <stdexcept>

namespace Dataset {

    // Constructor
    Dataset::Dataset(const std::string& file_path) {
        load_dataset(file_path);
    }

    Dataset::Dataset() {
    // Initialize headers as an empty vector
    headers = std::vector<std::string>();
    // Initialize data as an empty unordered_map
    data = std::unordered_map<std::string, std::vector<std::string>>();
    // Optionally, log or set default behavior (e.g., display a message or set some flags)
    std::cout << "Dataset created with no data loaded." << std::endl;
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
  
} // namespace Dataset
