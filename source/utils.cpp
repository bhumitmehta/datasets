#include "utils.h"
#include "dataset.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Dataset {
    std::vector<std::string> Dataset::get_column(const std::string& column_name) const {
        if (data.find(column_name) == data.end()) {
            throw std::runtime_error("Column '" + column_name + "' not found!");
        }
        return data.at(column_name);
    }

     std::vector<std::string> Dataset::operator[](const std::string& column_name) const {
        return get_column(column_name);
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

    std::string Dataset::dataset(LanguageCode lang) const {
        switch (lang) {
            case LanguageCode::DE: return "Hallo, dataset!";
            case LanguageCode::ES: return "¡Hola, dataset!";
            case LanguageCode::FR: return "Bonjour, dataset!";
            default: return "Hello, dataset!";
        }
    }
}