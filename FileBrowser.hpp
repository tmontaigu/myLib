#ifndef FILE_BROWSER_H
#define FILE_BROWSER_H

#include <vector>

using namespace std;

namespace FileOperation {

    class FileBrowser {
        /* Constructor & Destructor */
        public:
            FileBrowser();
            ~FileBrowser();

        /* Methods */
        public:
            /*
             * Find all the files in the folder and sub-folders that have the wanted extension,
             * and/or contain a specified string in their name.
             * Input:
             * folderPath: path tho the starting folder to begin the look up
             * extension: extension of the file you want to find, not used if NULL
             * searchString: string that the wanted files contain, not used if NULL
             * maxRecusion: indicate how many nested-subfolder you want the function to look in
             *              if 0 then no sub-folder visited
             * foundFiles: vector that will contain the path of all the found files
             *
             *  /!\ When you're finished with these, you must delete all de filePath in the vector using 
             *      delete /!\
             */
            void FindFiles(char *folderPath, char *extension, char *searchString, int maxRecursion, vector<char*> &foundFiles);
            /*
             * Find all the files in the folder (only) that have the wanted extension,
             * and/or contain a specified string in their name.
             * Input:
             * folderPath: path tho the starting folder to begin the look up
             * extension: extension of the file you want to find, not used if NULL
             * searchString: string that the wanted files contain, not used if NULL
             * foundFiles: vector that will contain the path of all the found files
             *
             *  /!\ When you're finished with these, you must delete all de filePath in the vector using 
             *      delete /!\
             */
            void FindFiles(char *folderPath, char *extension, char *searchString, vector<char*> &foundFiles);
    };

}; // namespace
#endif
