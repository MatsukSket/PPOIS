#pragma once

#include "Room.h"
#include "../shop/Souvenir.h"
#include <vector>
#include <memory>
#include <string>

class Shop : public Room {
public:
    explicit Shop(std::string name);

    void addSouvenir(std::unique_ptr<Souvenir> item);
    void buySouvenir(const std::string& itemName);
    bool hasSouvenir(const std::string& name) const;
    double getSouvenirPrice(const std::string& name) const;

    size_t getSouvenirCount() const { return inventory_.size(); }
    std::string getDescription() const override;

private:
    std::vector<std::unique_ptr<Souvenir>> inventory_;
};