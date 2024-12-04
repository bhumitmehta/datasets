#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

namespace Dataset {

    enum class LanguageCode { EN, DE, ES, FR };

    
    
    
        std::vector<std::string> get_column(const std::string& column_name) const;

        std::vector<std::string> operator[](const std::string& column_name) const;

        /// @brief 
        /// @param column_name 
        /// @param values 
        void add_column(const std::string& column_name, const std::vector<std::string>& values);

        std::string dataset(LanguageCode lang = LanguageCode::EN) const;

        std::vector<std::string> copyRow(int index);


}  // namespace Dataset
