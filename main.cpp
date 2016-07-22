#include "FileBrowser.hpp"
#include "FileOperation.hpp"



#include <iostream>
#include <vector>

using namespace std;
using namespace FileOperation;

int main (int argc, char **argv) {
   /* 
    FileBrowser *fb = new FileBrowser();
    vector<char*> files; 

    fb->FindFiles(argv[1], argv[2], argv[3], atoi(argv[4]), files);

    cout << "Number of Found Files: " << files.size() << endl;
    for (int i = 0; i < files.size(); i++) {
        cout << files[i] << endl;
        delete[] files[i];
    }
   delete fb; 
   */
/*
    cout << argv[1] << endl;
    char *res = NULL;
    res = RemovelastSeparator(argv[1], '/');
    if (res != NULL) {
        cout << res << endl;
        delete[] res;
    }
    */


    char *withExtention = "/home/world/of/warcraft.exe";
    char *withoutExtension;

    withoutExtension = RemoveExtension(withExtention, '.', '/');
    cout << "With Extension: " << withExtention << endl;
    cout << "Without Extention: " << withoutExtension << endl;
    free(withoutExtension);

}
