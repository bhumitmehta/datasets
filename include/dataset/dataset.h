#pragma once

#include "io.h"
#include "statistics.h"
#include "utils.h"
#include "manipulation.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace Dataset {

    // Enum for language codes to be used for localized greetings
    enum class LanguageCode { EN, DE, ES, FR };

    /**
     * @brief A class for handling and processing a dataset
     */
    class Dataset {
    private:
        std::vector<std::string> headers;  // Column names
        std::unordered_map<std::string, std::vector<std::string>> data;      // Stores the rows of data

    public:
        /**
         * @brief Creates a new dataset object
         * @param file_path the path to the CSV file to load
         */
        Dataset(const std::string& file_path);

        Dataset();

        /**
         * @brief Loads a dataset from a CSV file
         * @param file_path the path to the CSV file
         */
        void load_dataset(const std::string& file_path);

        /**
         * @brief Loads a dataset from a CSV file
         * @param file_path the path to the CSV file
         */
        void save(const std::string& file_path);

        /**
         * @brief Returns the first n rows of the dataset (default 10)
         * @param n number of rows to print
         */
        void head(int n = 10) const;

        /**
         * @brief Gets all values from a specific column
         * @param column_name the column name to fetch values from
         * @return a vector of strings containing the values from that column
         */
        std::vector<std::string> get_column(const std::string& column_name) const;

        /**
         * @brief Adds a new column to the dataset
         * @param column_name Name of the new column
         * @param values Values to add to the new column
         */
        void add_column(const std::string& column_name, const std::vector<std::string>& values);

        std::vector<std::string> Dataset::operator[](const std::string& column_name) const ;






        std::string Dataset::dataset(LanguageCode lang) const;



        void sort_by_column(const std::string& column_name, bool ascending = true);
        Dataset filter(const std::string& column_name, const std::string& value) const;
        void drop_column(const std::string& column_name);
        void drop_row(int row_index);
        Dataset merge(const Dataset& other, const std::string& column_name, bool is_outer_join = false);
    };
} // namespace Dataset
