#include "CSVFile.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

//----------------------------------------------------------------------------------------------------
CSVFile::CSVFile(char *path) {
    this->filePath = path;
}
//----------------------------------------------------------------------------------------------------
CSVFile::~CSVFile(){
}
//----------------------------------------------------------------------------------------------------
void CSVFile::Read() {
    ifstream csvFile (this->filePath);

    if (!csvFile) {
        cout << "Error Opening the file" << endl;
        return;
    }
    
    string value;
    string firstLine;
    
    
    getline(csvFile,firstLine);

    int numberOfFields = 0;

    Analyze(firstLine,this->fields, numberOfFields);

    while (!csvFile.eof()) {
        string line;
        getline(csvFile, line);
        this->ReadLine(line, fields);
    }
 

    csvFile.close();
}
//----------------------------------------------------------------------------------------------------
int CSVFile::NumberOfDigits(string str) {
    int count = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isdigit(str[i]))
            count++;
    }
    return count;
}
//----------------------------------------------------------------------------------------------------
float CSVFile::PercentageOfdigits(string str) {
    return ( (float) NumberOfDigits(str)/str.size()) * 100.0;
}
//----------------------------------------------------------------------------------------------------
void CSVFile::Analyze(string firstLine, std::vector<valuesFields> &fields, int &numberOfFields) {
    string value;
    istringstream fL(firstLine);

    int fieldCounter = 0;
    while(getline(fL, value, ',')) {
        fieldCounter++;

        vector<double> newField;

        newField.push_back(strtod(value.c_str(),NULL));

        fields.push_back(newField);
    }
    numberOfFields = fieldCounter;
}
//----------------------------------------------------------------------------------------------------
void CSVFile::ReadLine(string line, std::vector<valuesFields> &fields) {
    string value;
    istringstream fL(line);

    unsigned int currentField = 0;
    while(getline(fL, value, ',')) {
        if (currentField > fields.size()) {
            cout << "ERROR too many fields " << endl;
        }
        double val = strtod(value.c_str(),NULL);
        if (val != 0 && val > -555 && val < 555)
            fields[currentField].push_back(val);
        currentField++;
    }
}
//----------------------------------------------------------------------------------------------------
std::vector<valuesFields> CSVFile::GetValues() {
    return this->fields;
}
                
