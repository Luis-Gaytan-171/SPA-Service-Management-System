#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service {
protected:
    std::string serviceName;
    int duration;       
    float basePrice;

public:
    Service();  // constructor 
    Service(const std::string& serviceName, int duration, float basePrice);  // overload

    // get n set
    std::string getServiceName() const;
    void setServiceName(const std::string& serviceName);

    int getDuration() const;
    void setDuration(int duration);

    float getBasePrice() const;
    void setBasePrice(float basePrice);

    // abstract methods
    virtual std::string displayDetails() const = 0;
    virtual float calculateFinalPrice() const = 0;
    virtual std::string displaySummary() const = 0;
};

#endif
