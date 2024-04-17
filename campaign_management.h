#ifndef CAMPAIGN_MANAGEMENT_H
#define CAMPAIGN_MANAGEMENT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

class Product { // Represents a product in a crowdfunding campaign
public:
    int Campaign_id;
    std::string title;
    std::string description;
    double goalAmount;
    std::string endDate;
    // Default constructor
    Product() : Campaign_id(0), title(""), description(""), goalAmount(0.0), endDate("") {}
    // Parameterized constructor
    Product(int id, std::string t, std::string d, double ga, std::string ed): Campaign_id(id), title(t), description(d), goalAmount(ga), endDate(ed) {}
};
// using hash table
std::unordered_map<int, Product> products;

// Function to create a new campaign
Product CreateCampaign(int Campaign_id, std::string title, std::string description, double goalAmount, std::string endDate) {
    // Create a new Product object
    Product newProduct(Campaign_id, title, description, goalAmount, endDate);
      // Add the new product to the products hash table
    products[Campaign_id] = newProduct;
    std::cout << "Added Campaign with ID " << Campaign_id << " to the products hash table." << std::endl;
    return newProduct; // Return the new product
}

// Class to represent a user
class User {
public:
    int userId;
    std::string name;
    std::string password;
    // Default constructor
    User(): userId(0), name(""), password("") {}
    // Constructor with parameters
    User(int id, std::string n, std::string p) : userId(id), name(n), password(p) {}
};

std::unordered_map<int, User> users;
// Create and add user to hash table
User CreateUser(int userId, std::string name, std::string password) {
    User newUser(userId, name, password);// Initialize new user
    users[userId] = newUser; // Add new user to hash table
    std::cout << "Added user with ID " << userId << " to the users hash table." << std::endl;
    return newUser;
}

// Represents a donation with its attributes
class Donation {
public:
    int id;
    int userId;
    int Campaign_id;
    double amount;
    // Default constructor
   Donation():id(0), userId(0), Campaign_id(0), amount(0.0) {}
    // Constructor with parameters
    Donation(int i, int u, int p, double a) : id(i), userId(u), Campaign_id(p), amount(a) {}
};

std::unordered_map<int, Donation> donations;

Donation createDonation(int id, int userId, int Campaign_id, double amount) {
    if (products.count(Campaign_id) == 0) {
            std::cout << "Error: Campaign with ID " << Campaign_id << " does not exist.\n";
            return Donation();
    }


   // Initialize a new donation with given parameters
    Donation newDonation(id, userId, Campaign_id, amount);
    // Initialize a new donation with given parameters
    donations[id] = newDonation;
    std::cout << "Added donation with ID " << id << " to the donations hash table." << std::endl;
    return newDonation;
}

bool doesUserExist(int userId) { // Checks if the user exists in the users map
    return users.count(userId) > 0; // Returns true if the user exists, false otherwise
}

// Function to display all campaigns
void displayProducts() {
    // Loop through the products map and display all of them
    for (auto const& product : products) {
        std::cout << "Campaign_id ID: " << product.first << std::endl;
        std::cout << "Title: " << product.second.title << std::endl;
        std::cout << "Description: " << product.second.description << std::endl;
        std::cout << "Goal Amount: " << product.second.goalAmount << std::endl;
        std::cout << "End Date: " << product.second.endDate << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}
// Function to display all users
void displayUsers() {
    // Iterate through the user map and display all
    for (auto const& user : users) {
        std::cout << "User ID: " << user.first << std::endl;
        std::cout << "Name: " << user.second.name << std::endl;
        std::cout << "Password: " << user.second.password << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}

void displayDonations() {
    //Loop through donations map and print out each donation's details
    for (auto const& donation : donations) {
        std::cout << "Donation ID: " << donation.first << std::endl;
        std::cout << "User ID: " << donation.second.userId << std::endl;
        std::cout << "Campaign ID: " << donation.second.Campaign_id << std::endl;
        std::cout << "Amount: " << donation.second.amount << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}
// Function to read campaigns from a CSV file
void readCampaignsFromCSV(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::cout << "File: " << filename << " is open" << std::endl;
        std::string line;
        // Skip the header line
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string field;
            Product product;
            std::getline(ss, field, ',');
            product.Campaign_id = std::stoi(field);
            std::getline(ss, field, ',');
            product.title = field;
            std::getline(ss, field, ',');
            product.description = field;
            std::getline(ss, field, ',');
            product.goalAmount = std::stod(field);
            std::getline(ss, field, ',');
            product.endDate = field;
            std::cout << "End date: " << product.endDate << std::endl;
            products[product.Campaign_id] = product;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

// Function to read users from a CSV file
void readUsersFromCSV(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        // Skip the header line
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string field;
            User user;
            std::getline(ss, field, ',');
            user.userId = std::stoi(field);
            std::getline(ss, field, ',');
            user.name = field;
            std::getline(ss, field, ',');
            user.password = field;
            std::cout << "User ID: " << user.userId << ", Name: " << user.name << ", Password: " << user.password << std::endl;            
            users[user.userId] = user;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

#endif // CAMPAIGN_MANAGEMENT_H