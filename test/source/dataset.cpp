#include "gtest/gtest.h"
#include "dataset.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <map>

class DatasetTest : public ::testing::Test {

protected:

    Dataset::Dataset dataset;
    void SetUp() override {
        // Initialize a dataset for testing.
        dataset.add_column("Name", {"Alice", "Bob", "Charlie"});
        dataset.add_column("Age", {"25", "30", "35"});
        dataset.add_column("City", {"New York", "Los Angeles", "Chicago"});
    }
};

TEST_F(DatasetTest, AddColumn) {
    // Test adding a new column.
    dataset.add_column("Country", {"USA", "USA", "USA"});
    // Check if the column was added correctly.
    auto country_column = dataset.get_column("Country");
    EXPECT_EQ(country_column.size(), 3);
    EXPECT_EQ(country_column[0], "USA");
}

TEST_F(DatasetTest, GetColumn) {
    // Test retrieving a column.
    auto age_column = dataset.get_column("Age");
    EXPECT_EQ(age_column.size(), 3);
    EXPECT_EQ(age_column[1], "30");

    // Check for non-existing column.
    EXPECT_THROW(dataset.get_column("NonExistent"), std::out_of_range);
}

// TEST_F(DatasetTest, FilterRows) {
//     // Filter rows where Age is greater than 30.
//     dataset.filter_rows([](const std::map<std::string, std::string>& row) {
//         return std::stoi(row.at("Age")) > 30;
//     });

//     // Check that only one row remains.
//     auto name_column = dataset.get_column("Name");
//     EXPECT_EQ(name_column.size(), 1);
//     EXPECT_EQ(name_column[0], "Charlie");
// }

// TEST_F(DatasetTest, GroupBy) {
//     // Test grouping by a column.
//     dataset.add_column("Group", {"A", "B", "A"});
//     auto groups = dataset.group_by("Group");

//     // Check the size of groups.
//     EXPECT_EQ(groups.size(), 2);
//     EXPECT_EQ(groups["A"].get_column("Name").size(), 2);
//     EXPECT_EQ(groups["B"].get_column("Name").size(), 1);
// }

// TEST_F(DatasetTest, Summarize) {
//     // Test summarizing a column.
//     auto result = dataset.summarize("Age", "mean");
//     EXPECT_EQ(result, 30.0); // Assuming summarize() handles "mean" operation.
// }

// TEST_F(DatasetTest, SaveAndLoadCSV) {
//     // Save the dataset to a CSV file.
//     dataset.save_to_csv("test_output.csv");

//     // Load the dataset back.
//     Dataset new_dataset;
//     new_dataset.load_from_csv("test_output.csv");

//     // Compare the loaded data with the original data.
//     auto name_column = new_dataset.get_column("Name");
//     EXPECT_EQ(name_column.size(), 3);
//     EXPECT_EQ(name_column[0], "Alice");
// }

TEST_F(DatasetTest, Exceptions) {
    // Test adding a column with a mismatched size.
    EXPECT_THROW(dataset.add_column("Invalid", {"Too", "Many", "Values", "Here"}), std::invalid_argument);
    // Test accessing a non-existent column.
    EXPECT_THROW(dataset.get_column("DoesNotExist"), std::out_of_range);
}
