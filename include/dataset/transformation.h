#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <stdexcept>

namespace Dataset {

    
    
        /**
         * @brief Normalizes a numeric column to the range [0, 1].
         * @param column_name the name of the column to normalize.
         * @return a vector of normalized values.
         */
        std::vector<double> normalize(const std::string& column_name);

        /**
         * @brief Standardizes a numeric column (zero mean and unit variance).
         * @param column_name the name of the column to standardize.
         * @return a vector of standardized values.
         */
        std::vector<double> standardize(const std::string& column_name);

        /**
         * @brief Applies one-hot encoding to a categorical column.
         * @param column_name the name of the column to encode.
         * @return a vector of vectors representing the one-hot encoded data.
         */
        std::vector<std::vector<int>> one_hot_encode(const std::string& column_name);

        /**
         * @brief Applies label encoding to a categorical column.
         * @param column_name the name of the column to encode.
         * @return a vector of integers representing the encoded labels.
         */
        std::vector<int> label_encode(const std::string& column_name);

        /**
         * @brief Bins a numeric column into discrete categories.
         * @param column_name the name of the column to bin.
         * @param bins the number of bins or a vector of bin edges.
         * @return a vector of strings or integers representing the bin labels.
         */
        std::vector<std::string> bin_column(const std::string& column_name, int bins);

        /**
         * @brief Applies a logarithmic transformation to a numeric column.
         * @param column_name the name of the column to transform.
         * @return a vector of logarithmically transformed values.
         */
        std::vector<double> log_transform(const std::string& column_name);
    

}  // namespace Dataset
