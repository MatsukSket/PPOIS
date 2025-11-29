#include "social_media/SocialMedia.h"
#include "social_media/Instagram.h"
#include "social_media/TikTok.h"
#include <UnitTest++/UnitTest++.h>

TEST(SocialMedia_ValidConstruction) {
    SocialMedia sm("MuseumArt", "museum_art", 50000, 1200, "Generic");
    CHECK_EQUAL("MuseumArt", sm.profileName());
    CHECK_EQUAL("museum_art", sm.username());
    CHECK_EQUAL(50000u, sm.followersCount());
    CHECK_EQUAL(1200u, sm.postCount());
    CHECK_EQUAL("Generic", sm.platformName());
}

TEST(Instagram_ValidConstruction) {
    Instagram ig("ModernMuseum", "modern_museum", 25000, 450, 120, "Art & Culture");
    CHECK_EQUAL("ModernMuseum", ig.profileName());
    CHECK_EQUAL("modern_museum", ig.username());
    CHECK_EQUAL(25000u, ig.followersCount());
    CHECK_EQUAL(450u, ig.postCount());
    CHECK_EQUAL(120u, ig.storiesCount());
    CHECK_EQUAL("Art & Culture", ig.bio());
    CHECK_EQUAL("Instagram", ig.platformName());
}

TEST(TikTok_ValidConstruction) {
    TikTok tt("MuseumVibes", "museum_vibes", 180000, 320, 2500000, 45000);
    CHECK_EQUAL("MuseumVibes", tt.profileName());
    CHECK_EQUAL("museum_vibes", tt.username());
    CHECK_EQUAL(180000u, tt.followersCount());
    CHECK_EQUAL(320u, tt.postCount());
    CHECK_EQUAL(2500000u, tt.likesCount());
    CHECK_EQUAL(45000u, tt.repostCount());
    CHECK_EQUAL("TikTok", tt.platformName());
}