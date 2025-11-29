#pragma once

#include "SocialMedia.h"
#include <string>

class Instagram : public SocialMedia {
public:
    Instagram(std::string profileName,
              std::string username,
              unsigned followersCount,
              unsigned postCount,
              unsigned storiesCount,
              std::string bio);

    unsigned storiesCount() const noexcept { return storiesCount_; }
    const std::string& bio() const noexcept { return bio_; }

private:
    unsigned storiesCount_;
    std::string bio_;
};