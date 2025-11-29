#include "SocialMedia.h"

SocialMedia::SocialMedia(std::string profileName,
                         std::string username,
                         unsigned followersCount,
                         unsigned postCount,
                         std::string platformName)
    : profileName_(std::move(profileName)),
      username_(std::move(username)),
      followersCount_(followersCount),
      postCount_(postCount),
      platformName_(std::move(platformName)) {}