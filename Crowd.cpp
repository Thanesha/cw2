#include "campaign_management.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;



int main() {

    readCampaignsFromCSV("campaigns.csv");
    // Read users data from a CSV file
    readUsersFromCSV("users.csv");
    int choice;
     while (true) {
    std::cout << "1. Display campaign file\n"; // Option to create a new campaign
    std::cout << "2. Display User file\n"; // Option to create a new user
    std::cout << "3. Create a new Campaign\n"; // Option to create a new donation
    std::cout << "4. Create a new User\n"; // Option to display all campaigns
    std::cout << "5. Create a new donation\n"; // Option to display all users
    std::cout << "6. Display all Campaign\n"; // Option to display all donations
    std::cout << "7. Display all users\n"; // Option to display all donations
    std::cout << "8. Display all donations\n"; // Option to display all donations
    std::cout << "0. Quit\n"; // Option to quit
    std::cout << "Enter your choice: \n";
    std::cin >> choice;
    // while loop until user enters 0
    std::ifstream file("campaigns.csv");
        if (file.is_open()) {
            
        } else {
            std::cout << "Unable to open file: campaigns.csv" << std::endl;
        }
        switch (choice) {
           
            case 1:  // Display the contents of the campaigns.csv file
                if (file.is_open()) {
                    std::cout << "File: campaigns is open" << std::endl;
                    std::string line;
                    while (std::getline(file, line)) {
                        std::stringstream ss(line);
                        std::string field;
                        while (std::getline(ss, field, ',')) {
                            std::cout << field << "\t";
                        }
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "Unable to open file: campaigns.csv" << std::endl;
                }
                break;
            
           case 2: {
                    // Display the contents of the users.csv file
                std::ifstream file2("users.csv");
                if (file2.is_open()) {
                    std::cout << "File: User is open" << std::endl;
                    std::string line;
                    while (std::getline(file2, line)) {
                        std::stringstream ss(line);
                        std::string field;
                        while (std::getline(ss, field, ',')) {
                            std::cout << field << "\t";
                        }
                        std::cout << std::endl;
                    }
                    file2.close();
                } else {
                    std::cout << "Unable to open file: users.csv" << std::endl;
                }
                break;
            }
             //  Create campaign
            case 3:{
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
            // create User 
            case 4:
                {
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
            // create donations
            case 5:
                {
                int id;
                int userId;
                int productId;
                double amount;
                std::cout << "Enter the donation details:\n";
                std::cout << "Donation ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                 if (donations.count(id) > 0) {
                    std::cout << "Error: Donation with ID " << id << " already exists.\n";
                    break;
                }
                std::cout << "User ID: ";
                std::cin >> userId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (users.count(userId) == 0) {
                    std::cout << "Error: User with ID " << userId << " does not exist.\n";
                    break;
                }
                std::cout << "Campaign ID: ";
                std::cin >> productId;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                 if (products.count(productId) == 0) {
                    std::cout << "Error: Campaign with ID " << productId<< " does not exist.\n";
                    break;
                }
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
          //  Dispaly all campaigns
            case 6:
                std::cout << "ALL Campaigns\n";
                displayProducts();
                break;
            // display all users
            case  7:
            std::cout << "ALL Users\n";
                displayUsers();
                break;
              //  display all donations
            case  8 : 
                std::cout << "ALL Donations\n";
                displayDonations();
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid choice.\n";
                break;
        }

        std::cout << "\n\n";
        // std::cin >> choice;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        file.close();

        if (choice == 0) {
            break;
        }
    }
    return 0;
}