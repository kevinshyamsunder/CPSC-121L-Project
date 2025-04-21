#ifndef LEFTOVER_RECORD_H
#define LEFTOVER_RECORD_H

#include <string>
#include "LeftoverRecord.h"
#include "crow/query_string.h"

// The LeftoverRecord class represents a record of leftover food.
// It stores details such as the date, meal, food name, quantity, reason for leftovers,
// disposal mechanism, and the cost of the leftover food.
// Converts a crow::query_string into a LeftoverRecord object.
LeftoverRecord QueryStringToLeftoverRecord(const crow::query_string &query_string) {
    LeftoverRecord record;
    record.SetDate(query_string.get("date"));
    record.SetMeal(query_string.get("meal"));
    record.SetFoodName(query_string.get("food_name"));
    record.SetQuantityInOz(std::stod(query_string.get("quantity_in_oz")));
    record.SetLeftoverReason(query_string.get("leftover_reason"));
    record.SetDisposalMechanism(query_string.get("disposal_mechanism"));
    record.SetCost(std::stod(query_string.get("cost")));
    return record;
}

class LeftoverRecord {
    public:
        // Sets the date of the leftover record (e.g., "2025-04-18").
        void SetDate(const std::string &date);
    
        // Sets the meal associated with the leftover (e.g., "Lunch", "Dinner").
        void SetMeal(const std::string &meal);
    
        // Sets the name of the food item (e.g., "Pasta", "Salad").
        void SetFoodName(const std::string &food_name);
    
        // Sets the quantity of the leftover food in ounces.
        void SetQuantityInOz(double qty_in_oz);
    
        // Sets the reason why the food became leftover (e.g., "Too much served").
        void SetLeftoverReason(const std::string &leftover_reason);
    
        // Sets the disposal mechanism for the leftover (e.g., "Compost", "Trash").
        void SetDisposalMechanism(const std::string &disposal_mechanism);
    
        // Sets the cost of the leftover food in dollars.
        void SetCost(double cost);
    
        // Gets the date of the leftover record.
        std::string GetDate() const;
    
        // Gets the meal associated with the leftover.
        std::string GetMeal() const;
    
        // Gets the name of the food item.
        std::string GetFoodName() const;
    
        // Gets the quantity of the leftover food in ounces.
        double GetQuantityInOz() const;
    
        // Gets the reason why the food became leftover.
        std::string GetLeftoverReason() const;
    
        // Gets the disposal mechanism for the leftover.
        std::string GetDisposalMechanism() const;
    
        // Gets the cost of the leftover food in dollars.
        double GetCost() const;
    
    private:
        // The date of the leftover record (e.g., "2025-04-18").
        std::string date_;
    
        // The meal associated with the leftover (e.g., "Lunch", "Dinner").
        std::string meal_;
    
        // The name of the food item (e.g., "Pasta", "Salad").
        std::string food_name_;
    
        // The quantity of the leftover food in ounces.
        double qty_in_oz_;
    
        // The reason why the food became leftover (e.g., "Too much served").
        std::string leftover_reason_;
    
        // The disposal mechanism for the leftover (e.g., "Compost", "Trash").
        std::string disposal_mechanism_;
    
        // The cost of the leftover food in dollars.
        double cost_;
    };
    
    #endif // LEFTOVER_RECORD_H