#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <vector>
#include <iostream>
#include <string>


union csvValue {
    char *c; 
    double d;
    int i;
};

typedef std::vector<double> valuesFields;

class CSVFile {
    /* Constructors & Destructors */
    public:
        CSVFile(char *path);
        ~CSVFile();

    /* Methods */
    public:
        void Read();
        float PercentageOfdigits(std::string str);
        int NumberOfDigits(std::string str);
        std::vector<valuesFields> GetValues();

    private:
        void Analyze(std::string firstLine, std::vector<valuesFields> &fields, int &numberOfFields);
        void ReadLine(std::string line, std::vector<valuesFields> &fields);

    /* Members */
    private:
        char *filePath;
        std::vector<valuesFields> fields;
        
};



#endif
