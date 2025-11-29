#pragma once

#include "Room.h"
#include "../shop/MenuItem.h"
#include <vector>
#include <memory>
#include <string>

class Cafe : public Room {
public:
    explicit Cafe(std::string name);

    void addMenuItem(MenuItem* item);

    void buyItem(const std::string& itemName);
    bool hasItem(const std::string& name) const;
    double getItemPrice(const std::string& name) const;

    size_t getMenuItemCount() const { return menu_.size(); }
    std::string getDescription() const override;

private:
    std::vector<MenuItem*> menu_;
};