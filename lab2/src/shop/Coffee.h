#include "Drink.h"

class Coffee : public Drink {
public:
    Coffee(std::string name, double price, std::string origin = "Unknown");
    
    const std::string& origin() const { return origin_; }
    std::string getType() const override { return "SpecialtyCoffee"; }
private:
    std::string origin_;
    std::string beanType_;
};