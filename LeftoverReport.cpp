#include "LeftoverReport.h"
#include <map>
#include <algorithm>
#include <numeric>

// Constructor
LeftoverReport::LeftoverReport(const std::vector<LeftoverRecord> &leftover_records)
    : leftover_records_(leftover_records) {}

// Example: Calculate the total cost of leftovers.
double LeftoverReport::TotalCostOfLeftovers() const {
    return std::accumulate(leftover_records_.begin(), leftover_records_.end(), 0.0,
        [](double sum, const LeftoverRecord &record) {
            return sum + record.GetCost();
        });
}