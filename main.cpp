#include <iostream>
#include <vector>
#include <string>

class Contact {
    std::string name;
    std::string number;

public:
    Contact() {
        name = "Unknown";
        number = "NoNumber";
    }
    Contact(const std::string& contactName, const std::string& contactNumber) {
        setName(contactName);
        setNumber(contactNumber);
    }
    bool setName(const std::string& contactName) {
        if (contactName.empty()) {
            return false;
        } else {
            name = contactName;
            return true;
        }
    }
    bool setNumber(const std::string& contactNumber) {
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
    std::string& getName() {
        return name;
    }
    std::string& getNumber() {
        return number;
    }
};

class Phone {
    std::vector<Contact> phoneBook;

public:
    void add() {
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
    void call() {
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
    void sms() {
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
private:
    static bool isPhoneNumber(const std::string& str) {
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
    static void writeSMS(std::string& message) {
        std::cout << "Enter message:" << std::endl;
        std::getline(std::cin, message);
    }
};

int main() {
    std::string op;
    Phone* phone = new Phone();
    do {
        std::cout << "Enter command: ";
        std::getline(std::cin, op);
        if (op == "add") {
            phone->add();
        }
        else if (op == "call") {
            phone->call();
        }
        else if (op == "sms") {
            phone->sms();
        }

    } while (op != "exit");
    delete phone;
    return 0;
}
