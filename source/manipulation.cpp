#include "dataset.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "manipulation.h"

namespace Dataset {
    void Dataset::sort_by_column(const std::string& column_name, bool ascending) {}

Dataset Dataset::filter(const std::string& column_name, const std::string& value) const {
        Dataset dataset;
  return dataset;
}

void Dataset::drop_column(const std::string& column_name) {}

void Dataset::drop_row(int row_index) {}

    Dataset Dataset::merge(const Dataset& other, const std::string& column_name,bool is_outer_join) {
                     Dataset dataset;
            return dataset;
}
}

