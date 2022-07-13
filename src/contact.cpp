#include <iostream>
#include "contact.h"

    Contact::Contact() {
        name = "Unknown";
        number = "NoNumber";
    }
    Contact::Contact(const std::string& contactName, const std::string& contactNumber) {
        setName(contactName);
        setNumber(contactNumber);
    }
    bool Contact::setName(const std::string& contactName) {
        if (contactName.empty()) {
            return false;
        } else {
            name = contactName;
            return true;
        }
    }
    bool Contact::setNumber(const std::string& contactNumber) {
        if (contactNumber.empty() || contactNumber.length() != 12) {
            return false;
        } else {
            if (contactNumber[0] != '+' || contactNumber[1] != '7') {
                return false;
            }
            for (int i = 2; i < 12; i++) {
                if (!std::isdigit(contactNumber[i])) {
                    return false;
                }
            }
            number = contactNumber;
            return true;
        }
    }
    std:: string& Contact::getName() {
        return name;
    }
    std::string& Contact::getNumber() {
        return number;
    }

