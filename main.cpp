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
     
    CSVFile *f = new CSVFile(argv[1]);
    f->Read();




    delete f;
}
