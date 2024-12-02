#include "transformation.h"

std::vector<double> Dataset::Dataset::normalize(const std::string& column_name) {
  return std::vector<double>();
}

std::vector<double> Dataset::Dataset::standardize(const std::string& column_name) {
  return std::vector<double>();
}

std::vector<std::vector<int>> Dataset::Dataset::one_hot_encode(const std::string& column_name) {
  return std::vector<std::vector<int>>();
}

std::vector<int> Dataset::Dataset::label_encode(const std::string& column_name) {
  return std::vector<int>();
}

std::vector<std::string> Dataset::Dataset::bin_column(const std::string& column_name, int bins) {
  return std::vector<std::string>();
}

std::vector<double> Dataset::Dataset::log_transform(const std::string& column_name) {
  return std::vector<double>();
}
