#pragma once
#include"Customer.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class ReadDelimitedFile
{

private:
    string fileDelimitor = ",";
    string filePathPrefix = "src/main/resources/";
    string splitByDelimitor;
    vector<string> parseByDelimiter(string row, char delimiter) {
        vector<string> listOfWords;
        string word = "";
        int wordSize = row.size();
        for (int counter = 0; counter < wordSize; counter++) {
            if (row.at(counter) == delimiter) {
                listOfWords.push_back(word);
                word = "";
            }
            else {
                word += row.at(counter);
            }
        }
        listOfWords.push_back(word);
        return listOfWords;

    }
public:
    ReadDelimitedFile() {

    }
    void setFileDelimitor(string fileDelimitor) {
        this->fileDelimitor = fileDelimitor;
    }

    vector<vector<string>> getFileData(string fileName) {
        vector<vector<string>> fileData = {};
        ifstream propertyFile;
        propertyFile.open(fileName);
        string row;
        while (getline(propertyFile, row)) {
            vector<string> listOfData = parseByDelimiter(row, ',');
            fileData.push_back(listOfData);
        }

        return fileData;
    }
};

