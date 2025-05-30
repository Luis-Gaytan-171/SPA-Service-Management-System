#include "Service.h"

// constructors
Service::Service() : serviceName(""), duration(0), basePrice(0.0f) {}

Service::Service(const std::string& serviceName, int duration, float basePrice) 
    : serviceName(serviceName), duration(duration), basePrice(basePrice) {}

// get n set
std::string Service::getServiceName() const {
    return serviceName;
}

void Service::setServiceName(const std::string& serviceName) {
    this->serviceName = serviceName;
}

int Service::getDuration() const {
    return duration;
}

void Service::setDuration(int duration) {
    this->duration = duration;
}

float Service::getBasePrice() const {
    return basePrice;
}

void Service::setBasePrice(float basePrice) {
    this->basePrice = basePrice;
}
