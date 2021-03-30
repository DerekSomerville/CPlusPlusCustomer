#pragma once
#include <string>
using namespace std;
class Customer {
private:
    string firstName;
    string lastName;
    string emailAddress;
    string password;
    const string dataSourceName = "customer";
public:
    Customer(string emailAddress, string firstName, string lastName, string password) {
        this->emailAddress = emailAddress;
        this->firstName = firstName;
        this->lastName = lastName;
        this->password = password;
    }
    Customer() {
    }
    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getEmailAddress() {
        return emailAddress;
    }

    string getPassword() {
        return password;
    }

    string getName() {
        return this->firstName + " " + this->lastName;
    }

    string toString() {
        return "Name: " + getName() + " Email Address " + emailAddress;
    }
};