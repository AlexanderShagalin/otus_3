#include <iostream>
#include <filesystem>

using namespace std;

#include "generator.h"


int main(int argc, char *argv[])
{
    map<string, map<string,funcDescription*>*> mapInterfaces;

    if(argc < 3)
        return -1;

    std::string path = string(argv[1]);
    for (const auto & entry : filesystem::directory_iterator(path))
    {

        string iterfacePath = entry.path().string();
        if(Parser(iterfacePath, &mapInterfaces))
        {
            CreateAdapters( &mapInterfaces, filesystem::path(iterfacePath).filename(), argv[2]);
        }
    }

    return 0;
}
