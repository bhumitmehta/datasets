#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Dataset {

    // Enum for language codes to be used for different localized greetings
    enum class LanguageCode { EN, DE, ES, FR };

    /**
     * @brief A class for handling and processing a dataset
     */
    class Dataset {
    private:
        std::unordered_map<std::string, int> headerMap; // Maps column names to indices
        std::vector<std::vector<std::string>> data;     // Stores the rows of data

    public:
        /**
         * @brief Creates a new dataset object
         * @param file_path the path to the CSV file to load
         */
        Dataset(const std::string& file_path);

        /**
         * @brief Loads a dataset from a CSV file
         * @param file_path the path to the CSV file
         */
        void load_dataset(const std::string& file_path);

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
         * @brief Gets the mean of a numeric column
         * @param column_name the column name to calculate the mean of
         * @return the mean value of the column
         */
        double mean(const std::string& column_name) const;

        /**
         * @brief Gets the median of a numeric column
         * @param column_name the column name to calculate the median of
         * @return the median value of the column
         */
        double median(const std::string& column_name) const;

        /**
         * @brief Gets the mode of a column
         * @param column_name the column name to calculate the mode of
         * @return the mode value of the column
         */
        std::string mode(const std::string& column_name) const;

        /**
         * @brief Overloads operator[] to access columns by name
         * @param column_name the column name to fetch values from
         * @return a vector of strings containing the column's values
         */
        std::vector<std::string> operator[](const std::string& column_name) const;

        /**
         * @brief Generates a localized greeting string based on the language code
         * @param lang the language to greet in (default is English)
         * @return the greeting string
         */
        std::string dataset(LanguageCode lang = LanguageCode::EN) const;
    };

}  // namespace Dataset
