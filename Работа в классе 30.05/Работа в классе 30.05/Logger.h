//
//  Logger.h
//  Работа в классе 30.05
//
//  Created by Станислав Егоров on 29.05.2024.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

enum LogLevel {
    INFO,
    DEBUG1
};

class Logger {
private:
    static Logger* instance;
    LogLevel level;

    Logger(LogLevel level) : level(level) {}

public:
    static Logger* getLogger();

    void setLevel(LogLevel level);

    void info(const std::string& message);
    void debug(const std::string& message);
};

#endif // LOGGER_H
