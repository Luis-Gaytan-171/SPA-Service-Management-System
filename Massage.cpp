#include "Massage.h"
#include <sstream>
#include <iomanip>

// constructors
Massage::Massage() : Service(), clientType("New"), appointmentTime("12:00 PM") {}

Massage::Massage(const std::string& serviceName, int duration, float basePrice,
                 const std::string& clientType, const std::string& appointmentTime)
    : Service(serviceName, duration, basePrice), clientType(clientType), appointmentTime(appointmentTime) {}

// get n set
std::string Massage::getClientType() const {
    return clientType;
}

void Massage::setClientType(const std::string& clientType) {
    this->clientType = clientType;
}

std::string Massage::getAppointmentTime() const {
    return appointmentTime;
}

void Massage::setAppointmentTime(const std::string& appointmentTime) {
    this->appointmentTime = appointmentTime;
}

// overide

std::string Massage::displayDetails() const {
    std::ostringstream oss;
    oss << "Service: " << serviceName << "\n";
    oss << "Duration: " << duration << " minutes\n";
    oss << "Base Price: $" << std::fixed << std::setprecision(2) << basePrice << "\n";
    oss << "Time: " << appointmentTime << "\n";
    if (!clientType.empty()) {
        oss << "Client Type: " << clientType << "\n";
    }
    return oss.str();
}

float Massage::calculateFinalPrice() const {
    float finalPrice = basePrice;

    if (duration > 60) {
        finalPrice += 200.0f;
    }

    if (clientType == "Returning") {
        finalPrice *= 0.9f;
    }

    return finalPrice;
}

// overload: acepta descuento extra (0 a 1)
float Massage::calculateFinalPrice(float discount) const {
    float baseFinal = calculateFinalPrice();

    if (discount > 0 && discount < 1) {
        baseFinal *= (1 - discount);
    }

    return baseFinal;
}

std::string Massage::displaySummary() const {
    std::ostringstream oss;
    oss << displayDetails();

    if (duration > 60) {
        oss << "Note: Duration exceeds 60 minutes. Surcharge applied: $200\n";
    }
    if (clientType == "Returning") {
        oss << "Note: Returning client discount applied: 10%\n";
    }
    oss << "Final Price: $" << std::fixed << std::setprecision(2) << calculateFinalPrice() << "\n";
    oss << "Booking Confirmed\n";
    oss << "=========================================\n";
    return oss.str();
}
