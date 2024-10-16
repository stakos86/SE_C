//
//  Logger.cpp
//  Работа в классе 30.05
//
//  Created by Станислав Егоров on 29.05.2024.
//

#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger* Logger::getLogger() {
    if (!instance) {
        instance = new Logger(INFO);
    }
    return instance;
}

void Logger::setLevel(LogLevel level) {
    this->level = level;
}

void Logger::info(const std::string& message) {
    if (level >= INFO) {
        std::cout << "[INFO] " << message << std::endl;
    }
}

void Logger::debug(const std::string& message) {
    if (level >= DEBUG) {
        std::cout << "[DEBUG] " << message << std::endl;
    }
}
