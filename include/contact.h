#include <iostream>
#pragma once

class Contact {
    std::string name;
    std::string number;

public:
    Contact();
    Contact(const std::string& contactName, const std::string& contactNumber);
    bool setName(const std::string& contactName);
    bool setNumber(const std::string& contactNumber);
    std::string& getName();
    std::string& getNumber();
};
