#ifndef LEFTOVER_TRACKER_BACKEND_H
#define LEFTOVER_TRACKER_BACKEND_H

#include <string>
#include "LeftoverTracker.h"
#include "crow/json.h"
#include "LeftoverTrackerBackend.h"

// Adds a new record to the tracker.
crow::json::wvalue LeftoverTrackerBackend::AddRecord(const crow::query_string &query_string) {
    LeftoverRecord record = QueryStringToLeftoverRecord(query_string);
    bool success = tracker_.AddRecord(record);

    crow::json::wvalue response;
    response["success"] = success;
    response["message"] = success ? "Record added successfully." : "Duplicate record. Not added.";
    return response;
}

crow::json::wvalue LeftoverTrackerBackend::GetRecords() const {
    crow::json::wvalue records_json = crow::json::wvalue::list();
    const auto &records = tracker_.GetRecords();

    for (const auto &record : records) {
        records_json.push_back(LeftoverRecordToCrowJSON(record));
    }

    return records_json;
}

// The LeftoverTrackerBackend class handles interaction with the frontend and JSON file operations.
class LeftoverTrackerBackend {
public:
    // Constructor that accepts the file path of the JSON file.
    LeftoverTrackerBackend(const std::string &leftover_records_filepath);

    // Loads records from the JSON file into memory.
    bool LoadRecordsFromJSONFile();

    // Writes records from memory to the JSON file.
    bool WriteRecordsToJSONFile() const;

    // Adds a new record based on the query string from the frontend.
    crow::json::wvalue AddRecord(const crow::query_string &query_string);

    // Deletes a record based on the query string from the frontend.
    crow::json::wvalue DeleteRecord(const crow::query_string &query_string);

    // Retrieves all records in JSON format.
    crow::json::wvalue GetRecords() const;

    // Generates a report and returns it in JSON format.
    crow::json::wvalue GetLeftoverReport() const;

private:
    const std::string leftover_records_filepath_; // File path for the JSON file.
    LeftoverTracker tracker_; // Manages all leftover records in memory.
};

#endif // LEFTOVER_TRACKER_BACKEND_H