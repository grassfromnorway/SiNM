#include <iostream>
#include <string>
#include <cstdlib>


struct dbg{
std::string warning = "[!]";
std::string success = "[+]";
std::string error = "[-]";
};

int detectDS(){
    std::string DS;
    FILE* pipe = popen("echo $XDG_SESSION_TYPE", "r");
    if (!pipe) return 1;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        std::cout << buffer;
    }

    pclose(pipe);

    return 0;
}

int main(){
    dbg dbg;
    printf("%s Running..\n", dbg.warning.c_str());
    detectDS();



    return 0;
}