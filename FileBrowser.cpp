#include "FileBrowser.hpp"
#include "FileOperation.hpp"

#include <vector>
#include <iostream>

#include <cstdlib>
#include <sys/stat.h>
#include <dirent.h>


#define MAX_LENGTH 1024

using namespace std;
using namespace FileOperation;

//----------------------------------------------------------------------------------------------------
FileOperation::FileBrowser::FileBrowser() {
}
//----------------------------------------------------------------------------------------------------
FileOperation::FileBrowser::~FileBrowser() {
}
//----------------------------------------------------------------------------------------------------
void FileBrowser::FindFiles(char *folderPath, char *extension, char *searchString, vector<char*> &foundFiles) {
    FindFiles(folderPath, extension,searchString,0, foundFiles);
}
//----------------------------------------------------------------------------------------------------
void FileOperation::FileBrowser::FindFiles(char *folderPath, char *extension, char *searchString , int maxRecursion, vector<char*> &foundFiles) {
    struct dirent *dp;
    DIR *dir;
    char filePath[MAX_LENGTH];

    if ( !IsADirectory(folderPath) ) {
       cout << folderPath << " is not a directory " << endl;
       return ;
    }

    if ( (dir = opendir(folderPath)) == NULL) {
        cerr << "Cannot open the directory " << endl;
        return ;
    }

    while( (dp = readdir(dir)) != NULL)
    {
        sprintf(filePath, "%s/%s", folderPath,dp->d_name);
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) {
            continue;
        }

        if (IsAFile(filePath)) {
            if ( extension != NULL && searchString != NULL) {
                if ( IsFileExtension(filePath, extension) && FileNameContains(filePath, searchString)) {
                    char *file = new char[strlen(filePath)+1];
                    memcpy(file, filePath, strlen(filePath));
                    foundFiles.push_back(file);
                }
            }
            else if (searchString == NULL) {
                if ( IsFileExtension(filePath, extension)) {
                    char *file = new char[strlen(filePath)+1];
                    memcpy(file, filePath, strlen(filePath)+1);
                    foundFiles.push_back(file);
                }
            }
            else if (extension == NULL) {
                if (FileNameContains(filePath, searchString)) { 
                    char *file = new char[strlen(filePath)+1];
                    memcpy(file, filePath, strlen(filePath)+1);
                    foundFiles.push_back(file);
                }
            }

        }
        else if (Exists(filePath) && IsADirectory(filePath) && maxRecursion > 0) {
            FindFiles(filePath, extension, searchString, maxRecursion-1, foundFiles);
        }
    }
    free(dir);
    free(dp);
    return;    
}


