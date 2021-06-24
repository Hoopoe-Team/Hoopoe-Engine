#include <dirent.h>
#include <iostream>

#include "../../Core/include/Types.h"

int main(int argc, char* argv[]) 
{
    if (argc > 1) 
    {
        for(int i = 1; i < argc; ++i) 
        {
            Hoopoe::String command = Hoopoe::String("./") + Hoopoe::String("utests/") + Hoopoe::String("Test") + Hoopoe::String(argv[i]);
            system(command.c_str());
        }
    } 
    else // runs all tests from utests directory. (only for Linux)
    {
        DIR *dir = opendir("./utests/");

        if(dir != NULL)
        {
            struct dirent *ent;
            while((ent = readdir(dir)) != NULL)
            {
                if(ent->d_type != DT_DIR)
                    system(Hoopoe::String(Hoopoe::String("./utests/") + Hoopoe::String(ent->d_name)).c_str());
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
