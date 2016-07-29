#include "FileOperation.hpp"

#include <iostream>
#include <cstring>


using namespace std;
using namespace FileOperation;

bool TestRemoveExtension(char *path, char*expectedResult, char dot, char sep);
bool TestRemoveLastSeperator(char *path, char* expectedResult, char sep);

int main(int argc, char **argv) {
        
    cout << "-> Test FileOperation <-" << endl;

    /* RemoveExtension Tests */

    TestRemoveExtension("/world/of/warcraft.exe", "/world/of/warcraft", '.' , '/');
    TestRemoveExtension("world/of/warcraft.exe", "world/of/warcraft", '.', '/');
    TestRemoveExtension("world\\of\\warcraft.exe", "world\\of\\warcraft", '.', '\\');
    TestRemoveExtension("\\world\\of\\warcraft.exe", "\\world\\of\\warcraft", '.', '\\');
    TestRemoveExtension("warcraft.exe", "warcraft",'.' ,'/' );
    TestRemoveExtension("warcraft.exe", "warcraft",'.' ,'/' );
    TestRemoveExtension("battle.net/warcraft/wow.exe", "battle.net/warcraft/wow", '.', '/');
    TestRemoveExtension("battle.net/warcraft/wow.exe", "battle.net/warcraft/wow", '.', 0);

    cout << "-> Tests Ok !" << endl;

    cout << "-> Test RemoveLastSeparator <-" << endl;
    TestRemoveLastSeperator("GNU/", "GNU", '/');
    TestRemoveLastSeperator(NULL, NULL , '/');
    cout << "-> Tests Ok !" << endl;

}

bool TestRemoveExtension(char *path, char* expectedResult, char dot, char sep) {
    char *res;
    bool failed = false;

    res = RemoveExtension(path, dot, sep);
    if (strcmp(res,expectedResult)) {
        cout << " Error " << endl;
        cout << "Got: " << res << " Expected: " << expectedResult << endl;
        failed = true;
    }
    delete[] res;
    return failed;


}
bool TestRemoveLastSeperator(char *path, char* expectedResult, char sep) {
    char *res = NULL;
    bool failed = false;

    res = RemoveLastSeparator(path, sep);
        
    if (expectedResult == NULL && res == NULL)
        return false;

    if (strcmp(res,expectedResult)) {
        cout << " Error " << endl;
        cout << "Got: " << res << " Expected: " << expectedResult << endl;
        failed = true;
    }
    delete[] res;
    return failed;


}
