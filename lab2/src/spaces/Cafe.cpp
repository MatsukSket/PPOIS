#include "Cafe.h"
#include <algorithm>
#include <stdexcept>

Cafe::Cafe(std::string name) : Room(std::move(name)) {}

void Cafe::addMenuItem(MenuItem* item) {
    menu_.push_back(std::move(item));
}

bool Cafe::hasItem(const std::string& name) const {
    return std::find_if(menu_.begin(), menu_.end(),
        [&](const auto& item) { return item->name() == name; }) != menu_.end();
}

double Cafe::getItemPrice(const std::string& name) const {
    auto it = std::find_if(menu_.begin(), menu_.end(),
        [&](const auto& item) { return item->name() == name; });
    if (it != menu_.end()) {
        return (*it)->price();
    }
    throw std::runtime_error("Item not found in cafe");
}

void Cafe::buyItem(const std::string& itemName) {
    auto it = std::find_if(menu_.begin(), menu_.end(),
        [&](const auto& item) { return item->name() == itemName; });
    if (it != menu_.end()) {
        menu_.erase(it); 
    } else {
        throw std::runtime_error("Item not available for purchase");
    }
}

std::string Cafe::getDescription() const {
    return "Cafe '" + name() + "': " + std::to_string(menu_.size()) + " items";
}