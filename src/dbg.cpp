#include "dbg.h"
#include <QDebug>

dbg db;

void logMessage(const char *message, const char *status) {
    qDebug() << status << message;
}