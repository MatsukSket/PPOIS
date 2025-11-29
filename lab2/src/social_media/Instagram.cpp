#include "Instagram.h"

Instagram::Instagram(std::string profileName,
                     std::string username,
                     unsigned followersCount,
                     unsigned postCount,
                     unsigned storiesCount,
                     std::string bio)
    : SocialMedia(std::move(profileName),
                  std::move(username),
                  followersCount,
                  postCount,
                  "Instagram"),
      storiesCount_(storiesCount),
      bio_(std::move(bio)) {}