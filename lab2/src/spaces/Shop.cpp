#include "Shop.h"
#include <algorithm>
#include <stdexcept>

Shop::Shop(std::string name) : Room(std::move(name)) {}

void Shop::addSouvenir(std::unique_ptr<Souvenir> item) {
    inventory_.push_back(std::move(item));
}

bool Shop::hasSouvenir(const std::string& name) const {
    return std::find_if(inventory_.begin(), inventory_.end(),
        [&](const auto& item) { return item->name() == name; }) != inventory_.end();
}

double Shop::getSouvenirPrice(const std::string& name) const {
    auto it = std::find_if(inventory_.begin(), inventory_.end(),
        [&](const auto& item) { return item->name() == name; });
        
    if (it != inventory_.end())
        return (*it)->price();

    throw std::runtime_error("Souvenir not found in shop");
}

void Shop::buySouvenir(const std::string& itemName) {
    auto it = std::find_if(inventory_.begin(), inventory_.end(),
        [&](const auto& item) { return item->name() == itemName; });

    if (it != inventory_.end())
        inventory_.erase(it);
    else 
        throw std::runtime_error("Souvenir not available for purchase");
}

std::string Shop::getDescription() const {
    return "Shop '" + name() + "': " + std::to_string(inventory_.size()) + " souvenirs";
}