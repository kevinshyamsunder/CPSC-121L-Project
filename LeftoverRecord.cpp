#include "LeftoverRecord.h"

// Implementation of LeftoverRecord methods

// Sets the date of the leftover record (e.g., "2025-04-18").
void LeftoverRecord::SetDate(const std::string &date) { date_ = date; }

// Sets the meal associated with the leftover (e.g., "Lunch", "Dinner").
void LeftoverRecord::SetMeal(const std::string &meal) { meal_ = meal; }

// Sets the name of the food item (e.g., "Pasta", "Salad").
void LeftoverRecord::SetFoodName(const std::string &food_name) { food_name_ = food_name; }

// Sets the quantity of the leftover food in ounces.
void LeftoverRecord::SetQuantityInOz(double qty_in_oz) { qty_in_oz_ = qty_in_oz; }

// Sets the reason why the food became leftover (e.g., "Too much served").
void LeftoverRecord::SetLeftoverReason(const std::string &leftover_reason) { leftover_reason_ = leftover_reason; }

// Sets the disposal mechanism for the leftover (e.g., "Compost", "Trash").
void LeftoverRecord::SetDisposalMechanism(const std::string &disposal_mechanism) { disposal_mechanism_ = disposal_mechanism; }

// Sets the cost of the leftover food in dollars.
void LeftoverRecord::SetCost(double cost) { cost_ = cost; }

// Gets the date of the leftover record.
std::string LeftoverRecord::GetDate() const { return date_; }

// Gets the meal associated with the leftover.
std::string LeftoverRecord::GetMeal() const { return meal_; }

// Gets the name of the food item.
std::string LeftoverRecord::GetFoodName() const { return food_name_; }

// Gets the quantity of the leftover food in ounces.
double LeftoverRecord::GetQuantityInOz() const { return qty_in_oz_; }

// Gets the reason why the food became leftover.
std::string LeftoverRecord::GetLeftoverReason() const { return leftover_reason_; }

// Gets the disposal mechanism for the leftover.
std::string LeftoverRecord::GetDisposalMechanism() const { return disposal_mechanism_; }

// Gets the cost of the leftover food in dollars.
double LeftoverRecord::GetCost() const { return cost_; }