#pragma once
#include"AllCustomers.h"
#include"Customer.h"
#include <iostream>
#include <string>
using namespace std;
class LogIn
{
private:
    string input(string message) {
        string result;
        cout << message;
        cin >> result;
        return result;
    }

    string getPassword(string emailAddress) {
        AllCustomers allCustomers;
        vector<Customer> listOfCustomers = allCustomers.getListOfCustomers();
        string password = "";
        for ( Customer customer : listOfCustomers) {
            if (customer.getEmailAddress() == emailAddress) {
                password = customer.getPassword();
            }
        }
        return password;
    }

public: 
    void logIn() {
        string emailAddress = input("Enter email address");
        string password = getPassword(emailAddress);
        if (password == "") {
            cout << "You are not a user";
        }
        else if (password == input("Enter password")) {
            cout << "You are logged in";
        }
        else {
            cout << "Wrong password, no second chances";
        }
    }

};

