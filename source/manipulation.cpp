#include"dataset.h"
#include"manipulation.h"
#include <stdexcept>
#include <algorithm>
 
namespace Dataset {
    

        void Dataset::sort_by_column(const std::string& column_name, bool ascending) {
            auto it = headers.find(column_name);
            if (it == headers.end()) {
                throw std::runtime_error("Column not found: " + column_name);
            }

            std::vector<std::pair<std::string, std::vector<std::string>>> column_data;
            for (const auto& entry : data) {
                column_data.push_back(entry);
            }

            // Sorting based on the specified column
            std::sort(column_data.begin(), column_data.end(), [&](const auto& a, const auto& b) {
                auto idx = std::find(headers.begin(), headers.end(), column_name) - headers.begin();
                if (ascending) {
                    return a.second[idx] < b.second[idx];
                }
                return a.second[idx] > b.second[idx];
            });

            // Rebuild the dataset with sorted data
            for (size_t i = 0; i < headers.size(); ++i) {
                data[headers[i]] = column_data[i].second;
            }
        }

         Dataset filter(const std::string& column_name, const std::string& value) const{
            auto it = headers.find(column_name);

            if (it == headers.end()) {
                throw std::runtime_error("Column not found: " + column_name);
            }
            Dataset::Dataset newDataSet;
            for_each(headers.begin(),headers.end(),[](int index))


         }
         void drop_column(const std::string& column_name){

         }
         void drop_row(int row_index){

         }
         Dataset merge(const Dataset& other, const std::string& column_name, bool is_outer_join = false){

         }
    
}