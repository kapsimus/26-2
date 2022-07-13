#pragma once

class Phone {
    std::vector<Contact> phoneBook;

public:
    void add();
    void call();
    void sms();
private:
    static bool isPhoneNumber(const std::string& str);
    static void writeSMS(std::string& message);
};