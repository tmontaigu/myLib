#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H


#include <fstream>

namespace FileOperation {

    /*
     *  Removes the extension from a path to a file.
     *  mystr: Path to the file with extension
     *  dot: Is the extension separator
     *  sep: Is the path separator
     *
     *  Returns an allocated string identical to the original but without the extension.
     *  It must be freed when you're finished with it.
     *
     *  If you pass in NULL or the new string can't be allocated,
     *  it will return NULL
     *  
     *  Usage :
     *     char *s;
     *     s = remove_ext ("hello.txt", '.', '/'))); 
     *     free (s);
     */
    char *RemoveExtension(char *mystr, char dot, char sep);
    /*
     * Removes the last Separator of a path ONLY if it is the last char.
     * if there is none it returns NULL;
     * path: the path
     * sep: the seperator
     *
     * Example:
     * RemoveLastSeparator("/home/yoshi/", '/') -> /home/yoshi
     * RemoveLastSeparator("/home/yoshi", '/')  -> NULL
     *
     * The returned string must be deleted with 
     * delete[]
     */ 
    char *RemoveLastSeparator(char *path, char sep);
    
    bool IsFileExtension(char *path, char *extension);
    bool FileNameContains(char *filename, char *string);


    bool Exists(char *path);

    bool IsADirectory(char *path);
    bool IsAFolder(char *path);

    bool IsAFile(char *path); 

    long FileSize(char *filePath);
    long FileSize(std::ifstream &file);

};


#endif
