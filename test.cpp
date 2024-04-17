#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "campaign_management.h"
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

TEST_CASE("readCampaignsFromCSV reads campaigns from a CSV file and adds them to the products hash table") {
  std::string filename = "campaigns.csv";
  readCampaignsFromCSV(filename);
  std::cout << "Products size: " << products.size() << std::endl;
  REQUIRE( products.size() == 2 );
  Product product1 = products[1];
  REQUIRE(product1.Campaign_id == 1);
  REQUIRE(product1.title == "Product 1");
  REQUIRE(product1.description == "Description 1");
  REQUIRE(product1.goalAmount == Approx(1000.0));
  Product product2 = products[2];
  REQUIRE(product2.Campaign_id == 2);
  REQUIRE(product2.title == "Product 2");
  REQUIRE(product2.description == "Description 2");
  REQUIRE(product2.goalAmount == Approx(2000.0));

}

TEST_CASE("readUsersFromCSV reads users from a CSV file and adds them to the users hash table") {
  std::string filename = "users.csv";
  readUsersFromCSV(filename);
  REQUIRE(users.size() == 2);
  User user1 = users[1];
  REQUIRE(user1.userId == 1);
  REQUIRE(user1.name == "Luke");
  User user2 = users[2];
  REQUIRE(user2.userId == 2);
  REQUIRE(user2.name == "Sam");
}

TEST_CASE("Product class", "[Product]") {
    SECTION("Default constructor") {
        Product product;
        REQUIRE(product.Campaign_id == 0);
        REQUIRE(product.title.empty());
        REQUIRE(product.description.empty());
        REQUIRE(product.goalAmount == 0.0);
        REQUIRE(product.endDate.empty());
    }

    SECTION("Parameterized constructor") {
        Product product(1, "Test Campaign", "This is a test campaign.", 1000.0, "2023-12-31");
        REQUIRE(product.Campaign_id == 1);
        REQUIRE(product.title == "Test Campaign");
        REQUIRE(product.description == "This is a test campaign.");
        REQUIRE(product.goalAmount == 1000.0);
        REQUIRE(product.endDate == "2023-12-31");
    }

    SECTION("CreateCampaign function") {
        CreateCampaign(1, "Test Campaign", "This is a test campaign.", 1000.0, "2023-12-31");
        REQUIRE(products.size() == 2);
        REQUIRE(products.count(1) == 1);
        Product product = products[1];
        REQUIRE(product.Campaign_id == 1);
        REQUIRE(product.title == "Test Campaign");
        REQUIRE(product.description == "This is a test campaign.");
        REQUIRE(product.goalAmount == 1000.0);
        REQUIRE(product.endDate == "2023-12-31");
    }
}
TEST_CASE("doesUserExist returns false if a user does not exist in the users hash table") {
  users.clear();
  readUsersFromCSV("users.csv");
  std::cout << "Users size: " << users.size() << std::endl;
  REQUIRE( doesUserExist(2) == true );
}

TEST_CASE("User class", "[User]") {
    SECTION("Default constructor") {
        User user;
        REQUIRE(user.userId == 0);
        REQUIRE(user.name.empty());
        REQUIRE(user.password.empty());
    }

    SECTION("Parameterized constructor") {
        User user(2, "Alice", "password1");
        REQUIRE(user.userId == 2);
        REQUIRE(user.name == "Alice");
        REQUIRE(user.password == "password1");
    }

    SECTION("CreateUser function") {
        CreateUser(2, "Alice", "password1");
        REQUIRE(users.size() == 2);
        REQUIRE(users.count(1) == 1);
        User user = users[2];
        REQUIRE(user.userId == 2);
        REQUIRE(user.name == "Alice");
        REQUIRE(user.password == "password1");
    }

    SECTION("doesUserExist function") {
        CreateUser(2, "Alice", "password1");
        REQUIRE(doesUserExist(1) == true);
        REQUIRE(doesUserExist(2) == true);
    }
}



TEST_CASE("Donation class", "[Donation]") {
    SECTION("Default constructor") {
        Donation donation;
        REQUIRE(donation.id == 0);
        REQUIRE(donation.userId == 0);
        REQUIRE(donation.Campaign_id == 0);
        REQUIRE(donation.amount == 0.0);
    }

    SECTION("Parameterized constructor") {
        Donation donation(1, 1, 1, 50.0);
        REQUIRE(donation.id == 1);
        REQUIRE(donation.userId == 1);
        REQUIRE(donation.Campaign_id == 1);
        REQUIRE(donation.amount == 50.0);
    }

    SECTION("createDonation function") {
        createDonation(1, 1, 1, 50.0);
        REQUIRE(donations.size() == 1);
        REQUIRE(donations.count(1) == 1);
        Donation donation = donations[1];
        REQUIRE(donation.id == 1);
        REQUIRE(donation.userId == 1);
        REQUIRE(donation.Campaign_id == 1);
        REQUIRE(donation.amount == 50.0);
    }
}