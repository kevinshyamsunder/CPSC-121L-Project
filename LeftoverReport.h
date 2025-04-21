#ifndef LEFTOVER_REPORT_H
#define LEFTOVER_REPORT_H

#include <vector>
#include <string>
#include "LeftoverRecord.h"

// The LeftoverReport class generates a report based on a collection of LeftoverRecord objects.
class LeftoverReport {
public:
    // Constructor that accepts a vector of LeftoverRecord objects.
    LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);

    // Returns the names of the most common leftover food items.
    std::vector<std::string> MostCommonLeftovers() const;

    // Returns the meals that produce the most costly leftovers.
    std::vector<std::string> MostCostlyLeftoverProducingMeals() const;

    // Returns the total cost of all leftovers.
    double TotalCostOfLeftovers() const;

    // Returns the most common reasons for leftovers.
    std::vector<std::string> MostCommonLeftoverReasons() const;

    // Returns the most common disposal mechanisms for leftovers.
    std::vector<std::string> MostCommonDisposalMechanisms() const;

    // Suggests strategies to reduce leftovers.
    std::vector<std::string> SuggestLeftoverReductionStrategies() const;

private:
    const std::vector<LeftoverRecord> &leftover_records_; // Reference to the collection of leftover records.
};

#endif // LEFTOVER_REPORT_H