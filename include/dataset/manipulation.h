#pragma once

#include <string>
#include "dataset.h"


namespace Dataset {
    class Dataset {
    /**
     * @brief Sorts the dataset based on a specified column.
     * @param column_name The column to sort by.
     * @param ascending If true, sorts in ascending order; otherwise, sorts in descending order.
     */
    void sort_by_column(const std::string& column_name, bool ascending = true);

    /**
     * @brief Filters the dataset based on a column value.
     * @param column_name The column to filter by.
     * @param value The value to filter the column by.
     * @return A new dataset containing the filtered rows.
     */
    Dataset filter(const std::string& column_name, const std::string& value) const;

    /**
     * @brief Drops a column from the dataset.
     * @param column_name The column to be dropped.
     */
    void drop_column(const std::string& column_name);

    /**
     * @brief Drops a row from the dataset by index.
     * @param row_index The index of the row to be dropped.
     */
    void drop_row(int row_index);

    /**
     * @brief Merges this dataset with another dataset based on a common column.
     * @param other The other dataset to merge with.
     * @param column_name The column on which to merge.
     * @param is_outer_join If true, performs an outer join; otherwise, an inner join.
     * @return A new dataset that is the result of the merge.
     */
    Dataset merge(const Dataset& other, const std::string& column_name, bool is_outer_join = false);
    };
} // namespace Dataset
