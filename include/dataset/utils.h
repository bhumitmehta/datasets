#pragma once
#include"dataset.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

namespace Dataset {

    enum class LanguageCode { EN, DE, ES, FR };

    class Dataset {
    public:
    
        std::vector<std::string> get_column(const std::string& column_name) const;

        std::vector<std::string> operator[](const std::string& column_name) const;

        void add_column(const std::string& column_name, const std::vector<std::string>& values);

        std::string dataset(LanguageCode lang = LanguageCode::EN) const;
    };

}  // namespace Dataset
