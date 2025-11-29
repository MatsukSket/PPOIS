#include "Souvenir.h"

class Keychain : public Souvenir {
public:
    Keychain(std::string name, double price, std::string material = "Metal");
    
    const std::string& material() const { return material_; }
    std::string getCategory() const override { return "Keychain"; }
private:
    std::string material_;
};