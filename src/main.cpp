#include <iostream>
#include <vector>
#include <string>
#include "contact.h"
#include "phone.h"



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
