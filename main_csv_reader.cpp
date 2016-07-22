#include "CSVFile.hpp"
#include "FileOperation.hpp"
#include "MathUtilities.hpp"
#include "FileOperation.hpp"
#include "FileBrowser.hpp"

#include <iostream>
#include <iomanip>
#include <libgen.h>

using namespace std;
using namespace FileOperation;

int main(int argc, char **argv) {
    
    string fieldsName[6] = {"Lat", "Lon", "SST", "WS", "SSS_corr", "SSS_uncorr"};

    FileBrowser *fb = new FileBrowser();

    vector<char *> csvFilesPath;
    fb->FindFiles(argv[1], ".csv", NULL, 10, csvFilesPath);
    CSVFile *f[csvFilesPath.size()];

    double **means = NULL;
    double **meanDevs = NULL;
    double **standardDevs = NULL;

    int numberOfFiles = csvFilesPath.size();
    int numberOfFields;

    for (int j = 0; j < csvFilesPath.size(); j++) {
        cout << endl << "\t-> File: " << basename(csvFilesPath[j]) << "<-" << endl << endl;
        f[j] = new CSVFile(csvFilesPath[j]);
        f[j]->Read();    

        vector<valuesFields> fields = f[j]->GetValues();
        numberOfFields = fields.size();


        if (means == NULL && meanDevs == NULL) {
            means = new double*[numberOfFields];
            meanDevs = new double*[numberOfFields];
            standardDevs = new double*[numberOfFields];
            for(int i = 0; i < numberOfFields; i++) {
                means[i] = new double[numberOfFiles];
                meanDevs[i] = new double[numberOfFiles];
                standardDevs[i] = new double[numberOfFiles];

            }
        }


        for (int i = 0; i < fields.size(); i++) {
            double mean = MathUtilities::ComputeMean(fields[i]);
            double meanDeviation = MathUtilities::ComputeMeanDeviation(fields[i]);
            double standardDev = MathUtilities::ComputeStandardDeviation(fields[i]);

            means[i][j] = mean;
            meanDevs[i][j] =  meanDeviation;
            standardDevs[i][j] = standardDev;
            
            cout << "\tField: " << setw(10); fieldsName == NULL ? cout << i : cout << fieldsName[i];
            cout << "\tMean: ";
            cout << setw(15) << mean; 
            cout << "\tStandard Deviation: ";
            cout << setw(15) << standardDev;
            cout << "   ";
            cout << "\tMean Deviation: ";
            cout << setw(15)  << meanDeviation << endl; 
            
        }
        fields.clear();
    }
    

    cout << endl<<  "\t-> OVERALL: Folder:" << dirname(csvFilesPath[1]) << " <-" << endl << endl;
    for (int i = 0; i <numberOfFields; i++) {
        cout << "\tField: " << setw(10); fieldsName == NULL ? cout << i : cout << fieldsName[i];
        cout << "\tMean: " << setw(15) << MathUtilities::ComputeMean(means[i], numberOfFiles);
        cout << "\tStandard Deviation " << setw(15) << MathUtilities::ComputeStandardDeviation(standardDevs[i], numberOfFiles);
        cout << "\tMean Deviation : " << setw(15) << MathUtilities::ComputeMeanDeviation(meanDevs[i], numberOfFiles);
        cout << endl;
    }

    
    for (int i = 0; i < csvFilesPath.size(); i++) {
        delete f[i];
        delete csvFilesPath[i];
    }
    for (int i = 0; i < numberOfFields; i++) {
        delete means[i];
        delete meanDevs[i];
        delete standardDevs[i];
    }
    delete[] means; 
    delete[] meanDevs; 
    delete[] standardDevs;
    delete fb;
    
    
}
