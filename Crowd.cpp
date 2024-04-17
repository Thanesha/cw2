#include "campaign_management.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;
 

int main() {
    int choice;
    std::cout << "1. Create a new Campaign\n"; // Option to create a new campaign
    std::cout << "2. Create a new user\n"; // Option to create a new user
    std::cout << "3. Create a new donation\n"; // Option to create a new donation
    std::cout << "4. Display all Campaigns\n"; // Option to display all campaigns
    std::cout << "5. Display all users\n"; // Option to display all users
    std::cout << "6. Display all donations\n"; // Option to display all donations
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    // while loop until user enters 0
    while (choice != 0) {
        switch (choice) {
            //  If user wants to create a new campaign, call function createCampaign
            case 1: {
                int Campaign_id;
                std::string title;
                std::string description;
                double goalAmount;
                std::string endDate;
                std::cout << "Enter the product details:\n";
                std::cout << "Campaign ID: ";
                std::cin >> Campaign_id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Title: ";
                std::getline(std::cin, title);
                std::cout << "Description: ";
                std::getline(std::cin, description);
                std::cout << "Goal Amount: ";
                std::cin >> goalAmount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "End Date (YYYY-MM-DD): ";
                std::getline(std::cin, endDate);
                CreateCampaign(Campaign_id, title, description, goalAmount, endDate);
                break;
            }
            // create User is called when user chooses option 2
           case 2: {
                int userId;
                std::string name;
                std::string password;
                std::cout << "Enter the user details:\n";
                std::cout << "User ID: ";
                std::cin >> userId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Name: ";
                std::getline(std::cin, name);
                std::cout << "Password: ";
                std::getline(std::cin, password);
                 // Check if user already exists in the hash table
                    if (doesUserExist(userId)) {
                        std::cout << "User already exists. Please choose a different user ID.\n";
                    } else {
                        // Create a new user object and add it to the hash table
                        User user(userId, name, password);
                        users[userId] = user;
                        std::cout << "Added user with ID " << userId << " to the users hash table." << std::endl;
                    }
                    break;
            }
            // create donations  is called when user chooses option 3
            case 3: {
                int id;
                int userId;
                int productId;
                double amount;
                std::cout << "Enter the donation details:\n";
                std::cout << "Donation ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "User ID: ";
                std::cin >> userId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Campaign ID: ";
                std::cin >> productId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Amount Donated: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (doesUserExist(userId)) {
                    createDonation(id, userId, productId, amount);
                } else {
                    std::cout << "User does not exist. Please create a new user first.\n";
                }
                break;
            }
            //  If user wants to view all campaigns
            case 4:
                std::cout << "ALL Campaigns\n";
                displayProducts();
                break;
            // display all users
            case 5:
                std::cout << "ALL Users\n";
                displayUsers();
                break;
            //  display all donations
            case 6:
                 std::cout << "ALL Donations\n";
                displayDonations();
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid choice.\n";
                break;
        }

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    }

    return 0;
}