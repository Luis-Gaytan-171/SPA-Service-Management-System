#include <iostream>
#include <limits>   // For clearing input buffer
#include "Massage.h"

int main() {
    std::string serviceName = "Personalized therapeutic massage";
    int duration;
    float basePrice;
    std::string clientType;
    std::string appointmentTime;

    std::cout << "Enter the massage duration (minutes): ";
    while (!(std::cin >> duration) || duration <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for duration: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the base price of the massage: ";
    while (!(std::cin >> basePrice) || basePrice <= 0) {
        std::cout << "Invalid input. Please enter a positive number for base price: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::cout << "Enter client type (New or Returning): ";
    std::getline(std::cin, clientType);

    // Convert clientType to uppercase for validation
    for (auto & c : clientType) c = toupper(c);

    while (clientType != "NEW" && clientType != "RETURNING") {
        std::cout << "Invalid client type. Please enter 'New' or 'Returning': ";
        std::getline(std::cin, clientType);
        for (auto & c : clientType) c = toupper(c);
    }

    std::cout << "Enter appointment time (e.g., 3:00 PM): ";
    std::getline(std::cin, appointmentTime);

    // Create Massage object
    Massage userMassage(serviceName, duration, basePrice, clientType == "NEW" ? "New" : "Returning", appointmentTime);

    // Show summary
    std::cout << "\nService Summary:\n";
    std::cout << userMassage.displaySummary();

    return 0;
}
