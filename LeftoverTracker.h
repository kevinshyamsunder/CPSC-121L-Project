#ifndef LEFTOVER_TRACKER_H
#define LEFTOVER_TRACKER_H

#include <vector>
#include "LeftoverRecord.h"
#include "LeftoverReport.h"

// The LeftoverTracker class manages a collection of LeftoverRecord objects.
class LeftoverTracker {
public:
    // Adds a new record to the tracker. Returns true if added successfully, false if duplicate.
    bool AddRecord(const LeftoverRecord &record);

    // Deletes a record from the tracker. Returns true if deleted successfully, false if not found.
    bool DeleteRecord(const LeftoverRecord &record);

    // Returns all records currently in the tracker.
    const std::vector<LeftoverRecord> &GetRecords() const;

    // Generates and returns a LeftoverReport based on the current records.
    LeftoverReport GetLeftoverReport() const;

private:
    std::vector<LeftoverRecord> leftover_records_; // Collection of leftover records.
};

#endif // LEFTOVER_TRACKER_H