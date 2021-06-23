#include "../../Core/include/Types.h"

int main(int argc, char* argv[]) 
{
    if (argc > 1) {
        for(int i = 1; i < argc; ++i) {
            Hoopoe::String command = Hoopoe::String("./") + Hoopoe::String("utests/") + Hoopoe::String("Test") + Hoopoe::String(argv[i]);
            system(command.c_str());
        }
    } else {
        system("./utests/*");
    }

    return 0;
}