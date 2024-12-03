#pragma once
#include "dataset.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <map>

namespace Dataset {

    class Dataset {
    public:
        double mean(const std::string& column_name) const;

        double median(const std::string& column_name) const;

        std::string mode(const std::string& column_name) const;
    };

}  // namespace Dataset
