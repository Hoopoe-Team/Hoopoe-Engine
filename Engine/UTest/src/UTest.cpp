#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <limits>
#include <stdlib.h>

#include "../../Core/include/Types.h"

int main(int argc, char* argv[]) 
{
    char buff[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len == -1) {
        std::cout << "Failed to get absolute path of utests.\n";
        return -1;
    }

    buff[len] = '\0';
    Hoopoe::String utestsPath = Hoopoe::String(dirname(buff)) + "/utests/";

    if (argc > 1) 
    {
        for(int i = 1; i < argc; ++i) 
        {
            Hoopoe::String command = utestsPath + Hoopoe::String("Test") + Hoopoe::String(argv[i]);
            system(command.c_str());
        }
    } 
    else // runs all tests from utests directory. (only for Linux)
    {
        DIR *dir = opendir(utestsPath.c_str());

        if(dir != NULL)
        {
            struct dirent *ent;
            while((ent = readdir(dir)) != NULL)
            {
                if(ent->d_type != DT_DIR)
                {
                    system(Hoopoe::String(utestsPath + Hoopoe::String(ent->d_name)).c_str());
                }
            }
        }
        else
        {
            std::cout << "Failed to open utests directory.\n";
            return 0;
        }

        closedir(dir);
    }

    return 0;
}