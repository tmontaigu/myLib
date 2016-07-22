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
        /*
        getline(csvFile, value, ',');
        value.erase(remove(value.begin(), value.end(), '\n'), value.end());

        if (value.empty())
            continue;

        
        if (PercentageOfdigits(value) > 60.0) {
            this->fields[currentField].push_back(strtod(value.c_str(), NULL));
        }

        currentField++;
        if(currentField == numberOfFields)
            currentField =0;
            */
    }
  // should go into a print csv function  
  /*
    for (int i = 0; i < this->fields[1].size(); i++){ 
        for (int j = 0; j < this->fields.size(); j++) {
            cerr << this->fields[j][i] << ",";
        }
       cerr << endl; 
    }
*/

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
        fields[currentField].push_back(strtod(value.c_str(),NULL));

        currentField++;
    }
}
//----------------------------------------------------------------------------------------------------
std::vector<valuesFields> CSVFile::GetValues() {
    return this->fields;
}
                
