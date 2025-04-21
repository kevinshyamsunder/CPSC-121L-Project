#include "LeftoverTracker.h"
#include <algorithm>

// Adds a new record to the tracker.
bool LeftoverTracker::AddRecord(const LeftoverRecord &record) {
    // Check for duplicates.
    auto it = std::find_if(leftover_records_.begin(), leftover_records_.end(),
        [&record](const LeftoverRecord &r) {
            return r.GetDate() == record.GetDate() &&
                   r.GetMeal() == record.GetMeal() &&
                   r.GetFoodName() == record.GetFoodName();
        });
    if (it != leftover_records_.end()) {
        return false; // Duplicate found.
    }
    leftover_records_.push_back(record);
    return true;
}

// Deletes a record from the tracker.
bool LeftoverTracker::DeleteRecord(const LeftoverRecord &record) {
    auto it = std::find_if(leftover_records_.begin(), leftover_records_.end(),
        [&record](const LeftoverRecord &r) {
            return r.GetDate() == record.GetDate() &&
                   r.GetMeal() == record.GetMeal() &&
                   r.GetFoodName() == record.GetFoodName();
        });
    if (it != leftover_records_.end()) {
        leftover_records_.erase(it);
        return true;
    }
    return false; // Record not found.
}

// Returns all records.
const std::vector<LeftoverRecord> &LeftoverTracker::GetRecords() const {
    return leftover_records_;
}

// Generates a report.
LeftoverReport LeftoverTracker::GetLeftoverReport() const {
    return LeftoverReport(leftover_records_);
}