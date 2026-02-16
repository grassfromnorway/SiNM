#ifndef DBG_H
#define DBG_H

#include <QDebug>

struct dbg{
    char S[5] = "[+] ";
    char F[5] = "[!] ";
    char I[5] = "[*] ";
};

extern dbg db;

void logMessage(const char *message, const char *status);

#endif  