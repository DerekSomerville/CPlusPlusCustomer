#pragma once
#include <iostream>
#include"Customer.h"
#include"ReadDelimitedFile.h"
using namespace std;
class AllCustomers
{
private:
    vector<Customer> listOfCustomer = {};
    bool customersLoaded = false;

    vector < vector<string>> loadRawCustomers() {
        ReadDelimitedFile readDelimitedFile;
        vector<vector<string>> rawCustomers = readDelimitedFile.getFileData("customer.csv");
        return rawCustomers;
    }

    vector<Customer>  loadAsCustomers() {
        vector<vector<string>> rawCustomers = loadRawCustomers();
        int counter = 0;
        for (vector<string> rawCustomer : rawCustomers) {
            Customer customer = Customer(rawCustomer[0], rawCustomer[1], rawCustomer[2], rawCustomer[3]);
            listOfCustomer.push_back(customer);
            counter += 1;
        }
        customersLoaded = true;
        return listOfCustomer;
    }
public:
    AllCustomers() {

    }

    vector<Customer>  getListOfCustomers() {
        if (!customersLoaded) {
            loadAsCustomers();
        }
        return listOfCustomer;
    }
};
