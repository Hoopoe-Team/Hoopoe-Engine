#include <string>

int main(int argc, char* argv[]) 
{
    if (argc > 1) {
        for(int i = 1; i < argc; ++i) {
            std::string command = std::string("./") + std::string("utests/") + std::string(argv[i]);
            system(argv[i]);
        }
    } else {
        system("./utests/*");
    }

    return 0;
}