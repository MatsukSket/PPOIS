#pragma once

#include "SocialMedia.h"

class TikTok : public SocialMedia {
public:
    TikTok(std::string profileName,
           std::string username,
           unsigned followersCount,
           unsigned postCount,
           unsigned likesCount,
           unsigned repostCount);

    unsigned likesCount() const noexcept { return likesCount_; }
    unsigned repostCount() const noexcept { return repostCount_; }

private:
    unsigned likesCount_;
    unsigned repostCount_;
};