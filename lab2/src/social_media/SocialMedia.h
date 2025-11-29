#pragma once

#include <string>

class SocialMedia {
public:
    explicit SocialMedia(std::string profileName,
                         std::string username,
                         unsigned followersCount,
                         unsigned postCount,
                         std::string platformName);

    const std::string& profileName() const noexcept { return profileName_; }
    const std::string& username() const noexcept { return username_; }
    unsigned followersCount() const noexcept { return followersCount_; }
    unsigned postCount() const noexcept { return postCount_; }
    const std::string& platformName() const noexcept { return platformName_; }

protected:
    std::string profileName_;
    std::string username_;
    unsigned followersCount_;
    unsigned postCount_;
    std::string platformName_;
    unsigned avgLikesPerPost_;
    std::string contactEmail_;
};