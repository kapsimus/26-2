#include <iostream>
#include <vector>
#include "contact.h"
#include "phone.h"

void Phone::add() {
    std::string name;
    std::string number;
    Contact* contact = new Contact();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    while (!contact->setName(name)) {
        std::cout << "Incorrect name. Enter name: ";
        std::getline(std::cin, name);
    }
    std::cout << "Enter number (+7XXXXXXXXXX): ";
    std::getline(std::cin, number);
    while (!contact->setNumber(number)) {
        std::cout << "Incorrect number. Enter number (+7XXXXXXXXXX): ";
        std::getline(std::cin, number);
    }
    phoneBook.push_back(*contact);
    delete contact;
}
void Phone::call() {
    std::string input;
    std::cout << "Enter name or phone number: ";
    std::getline(std::cin, input);
    if (isPhoneNumber(input)) {
        std::cout << "Call " << input << std::endl;
    } else {
        if (!input.empty()) {
            bool called = false;
            for (Contact contact: phoneBook) {
                if (contact.getName() == input) {
                    std::cout << "Call " << contact.getNumber() << std::endl;
                    called = true;
                }
            }
            if (!called) {
                std::cout << "This name is not in the phone book." <<std::endl;
            }
        }
    }

}
void Phone::sms() {
    std::string input;
    std::string message;
    std::cout << "Enter name or phone number: ";
    std::getline(std::cin, input);
    if (isPhoneNumber(input)) {
        writeSMS(message);
        std::cout << "SMS " << input << std::endl;
        std::cout << message << std::endl;
    }
    else {
        if (!input.empty()) {
            bool smsSent = false;
            for (Contact contact : phoneBook) {
                if (contact.getName() == input) {
                    writeSMS(message);
                    std::cout << "SMS " << contact.getNumber() << std::endl;
                    std::cout << message << std::endl;
                    smsSent = true;
                }
            }
            if (!smsSent) {
                std::cout << "This name is not in the phone book." << std::endl;
            }
        }
    }

}

bool Phone::isPhoneNumber(const std::string& str) {
    if (str.empty() || str.length() != 12) {
        return false;
    } else {
        if (str[0] != '+' || str[1] != '7') {
            return false;
        }
        for (int i = 2; i < 12; i++) {
            if (!std::isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }
}
void Phone::writeSMS(std::string& message) {
    std::cout << "Enter message:" << std::endl;
    std::getline(std::cin, message);
}

