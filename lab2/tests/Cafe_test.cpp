#include "spaces/Cafe.h"
#include "shop/MenuItem.h"
#include "shop/Drink.h"
#include "shop/Coffee.h"
#include "shop/Dessert.h"
#include <UnitTest++/UnitTest++.h>

TEST(Cafe_AddMenuItem_Valid) {
    Cafe cafe("Art Cafe");
    Coffee* coffee = new Coffee("Mocha", 4.5);
    cafe.addMenuItem(coffee);
    CHECK_EQUAL(1, cafe.getMenuItemCount());
}

TEST(Cafe_HasItem_Exists) {
    Cafe cafe("Test Cafe");
    Dessert* cake = new Dessert("Chocolate", 6.0);
    cafe.addMenuItem(cake);
    CHECK(cafe.hasItem("Chocolate"));
    CHECK(!cafe.hasItem("Pizza"));
}

TEST(Cafe_GetItemPrice_Valid) {
    Cafe cafe("Price Test");
    cafe.addMenuItem(new Coffee("Latte", 5.0));
    CHECK_CLOSE(5.0, cafe.getItemPrice("Latte"), 0.001);
}

TEST(Cafe_GetItemPrice_NotFound_Throws) {
    Cafe cafe("Empty");
    CHECK_THROW(cafe.getItemPrice("Espresso"), std::runtime_error);
}

TEST(Cafe_BuyItem_Valid) {
    Cafe cafe("Buy Cafe");
    cafe.addMenuItem(new Dessert("Muffin", 3.5));
    CHECK_EQUAL(1, cafe.getMenuItemCount());
    cafe.buyItem("Muffin");
    CHECK_EQUAL(0, cafe.getMenuItemCount());
    CHECK(!cafe.hasItem("Muffin"));
}

TEST(Cafe_BuyItem_NotAvailable_Throws) {
    Cafe cafe("No Stock");
    CHECK_THROW(cafe.buyItem("Croissant"), std::runtime_error);
}

TEST(Cafe_GetDescription_FormatsCorrectly) {
    Cafe cafe("Grand Cafe");
    cafe.addMenuItem(new Coffee("Cappuccino", 4.0));
    std::string desc = cafe.getDescription();
    CHECK(desc.find("Grand Cafe") != std::string::npos);
    CHECK(desc.find("1 items") != std::string::npos);
}

