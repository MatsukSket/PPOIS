#pragma once
#include <string>
#include <stdexcept>

class MuseumPass {
public:
    MuseumPass(std::string passId = "MP000",
               std::string ownerName = "Visitor",
               std::string passType = "Standard",
               std::string validFrom = "2025-01-01",
               std::string validUntil = "2025-12-31",
               int entryCount = 0);

    const std::string& passId() const noexcept { return passId_; }
    const std::string& ownerName() const noexcept { return ownerName_; }
    const std::string& passType() const noexcept { return passType_; }
    const std::string& validFrom() const noexcept { return validFrom_; }
    const std::string& validUntil() const noexcept { return validUntil_; }
    int entryCount() const noexcept { return entryCount_; }

private:
    std::string passId_;
    std::string ownerName_;
    std::string passType_;
    std::string validFrom_;
    std::string validUntil_;
    int entryCount_;
};