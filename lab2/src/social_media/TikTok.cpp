#include "TikTok.h"

TikTok::TikTok(std::string profileName,
               std::string username,
               unsigned followersCount,
               unsigned postCount,
               unsigned likesCount,
               unsigned repostCount)
    : SocialMedia(std::move(profileName),
                  std::move(username),
                  followersCount,
                  postCount,
                  "TikTok"),
      likesCount_(likesCount),
      repostCount_(repostCount) {}