#include "Souvenir.h"

class TShirt : public Souvenir {
public:
    TShirt(std::string name, double price, std::string size = "M");
    
    const std::string& size() const { return size_; }
    std::string getCategory() const override { return "TShirt"; }
private:
    std::string size_;
    std::string color_;
};