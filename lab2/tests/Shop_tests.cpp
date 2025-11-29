#include "spaces/Shop.h"
#include "shop/Souvenir.h"
#include "shop/TShirt.h"
#include "shop/Mug.h"
#include "shop/Book.h"
#include <UnitTest++/UnitTest++.h>

TEST(Shop_AddSouvenir_Valid) {
    Shop shop("Museum Store");
    shop.addSouvenir(std::make_unique<TShirt>("Logo Tee", 20.0, "M"));
    CHECK_EQUAL(1, shop.getSouvenirCount());
}

TEST(Shop_HasSouvenir_Exists) {
    Shop shop("Gift Shop");
    shop.addSouvenir(std::make_unique<Mug>("Art Mug", 15.0));
    CHECK(shop.hasSouvenir("Art Mug"));
    CHECK(!shop.hasSouvenir("Poster"));
}

TEST(Shop_GetSouvenirPrice_Valid) {
    Shop shop("Book Corner");
    shop.addSouvenir(std::make_unique<Book>("Guide", 25.0, "Museum Staff"));
    CHECK_CLOSE(25.0, shop.getSouvenirPrice("Guide"), 0.001);
}

TEST(Shop_GetSouvenirPrice_NotFound_Throws) {
    Shop shop("Empty");
    CHECK_THROW(shop.getSouvenirPrice("Rare Coin"), std::runtime_error);
}

TEST(Shop_BuySouvenir_Valid) {
    Shop shop("Buy Test");
    shop.addSouvenir(std::make_unique<TShirt>("Tee", 18.0));
    CHECK_EQUAL(1, shop.getSouvenirCount());
    shop.buySouvenir("Tee");
    CHECK_EQUAL(0, shop.getSouvenirCount());
    CHECK(!shop.hasSouvenir("Tee"));
}

TEST(Shop_BuySouvenir_NotAvailable_Throws) {
    Shop shop("Closed");
    CHECK_THROW(shop.buySouvenir("Statue"), std::runtime_error);
}

TEST(Shop_GetDescription_FormatsCorrectly) {
    Shop shop("Main Shop");
    shop.addSouvenir(std::make_unique<Book>("History", 30.0));
    std::string desc = shop.getDescription();
    CHECK(desc.find("Main Shop") != std::string::npos);
    CHECK(desc.find("1 souvenirs") != std::string::npos);
}
