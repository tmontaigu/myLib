#include "FileOperation.hpp"

#include <iostream>
#include <fstream>

#include <sys/stat.h>
#include <dirent.h>

using namespace std;
using namespace FileOperation;

//----------------------------------------------------------------------------------------------------
char *FileOperation::RemoveExtension(char* mystr, char dot, char sep) {
    char *retstr, *lastdot, *lastsep;
    // Error checks and allocate string.

    if (mystr == NULL)
        return NULL;
    if ((retstr = (char*)malloc (strlen (mystr) + 1)) == NULL)
        return NULL;
    // Make a copy and find the relevant characters.


    strcpy (retstr, mystr);
    lastdot = strrchr (retstr, dot);
    lastsep = (sep == 0) ? NULL : strrchr (retstr, sep);

    // If it has an extension separator.

    if (lastdot != NULL) {
    // and it's before the extenstion separator.
        if (lastsep != NULL) {
            if (lastsep < lastdot) {
             // then remove it.
              *lastdot = '\0';
            }
        }
    
        else {
            // Has extension separator with no path separator.
            *lastdot = '\0';
        }
    }
    //Return the modified string.
    return retstr;
}
//----------------------------------------------------------------------------------------------------
char *FileOperation::RemoveLastSeparator(char *path, char sep) {
    char *lastSep = NULL;
    char *retStr = NULL;
    int indexOfLatSep;
    int lengthOfPath;

    if ( path == NULL)
        return NULL;

    lastSep = strrchr(path, sep);
    if (lastSep == NULL) {
        return retStr;
    }

    indexOfLatSep = lastSep-path+1;
    lengthOfPath = strlen(path);


    if (lengthOfPath == indexOfLatSep) {
        retStr = new char[lengthOfPath+1];
        strcpy(retStr, path);
        retStr[indexOfLatSep-1] = '\0';
    }
    return retStr;
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::IsFileExtension(char *path, char *extension) {
   char *theExtension;

   theExtension = strrchr(path, extension[0]);
   if (theExtension==NULL)
       return false;
   return (strcmp(theExtension, extension) == 0);
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::FileNameContains(char *filename, char *string) {
    char *contain = strstr(filename, string);

    if(contain == NULL)
        return false;
    return true;
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::Exists(char *path) {
    struct stat sb;
    int res = stat(path, &sb);

    /* Exists but is not a folder */
    return res == 0;
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::IsADirectory(char *path) {
    struct stat sb;
    int res = stat(path, &sb);

    if(res == -1)
        return false;
    return S_ISDIR(sb.st_mode);
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::IsAFolder(char *path) {
    return IsADirectory(path);
}
//----------------------------------------------------------------------------------------------------
bool FileOperation::IsAFile(char *path) {
    struct stat sb;
    int res = stat(path, &sb);

    if (res == 0){
        return S_ISREG(sb.st_mode);
    }
    return false;
}
//----------------------------------------------------------------------------------------------------
long FileOperation::FileSize(char *filePath) {
    ifstream file(filePath);
    
    long size = FileSize(file);
    file.close();
    return size;
}
//----------------------------------------------------------------------------------------------------
long FileOperation::FileSize(ifstream &file)
{
    long pos = file.tellg();
    file.seekg(0, ios_base::end );
    long size = file.tellg();
    file.seekg(pos, ios_base::beg );
    return size;
}


