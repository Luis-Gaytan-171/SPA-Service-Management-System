#ifndef MASSAGE_H
#define MASSAGE_H

#include "Service.h"
#include <string>

class Massage : public Service {
private:
    std::string clientType;
    std::string appointmentTime;

public:
    Massage();  // constructor
    Massage(const std::string& serviceName, int duration, float basePrice,
            const std::string& clientType, const std::string& appointmentTime);  // constructor sobrecargado

    // get n set
    std::string getClientType() const;
    void setClientType(const std::string& clientType);

    std::string getAppointmentTime() const;
    void setAppointmentTime(const std::string& appointmentTime);

    // overide
    std::string displayDetails() const override;
    float calculateFinalPrice() const override;
    float calculateFinalPrice(float discount) const;  // overload
    std::string displaySummary() const override;
};

#endif
