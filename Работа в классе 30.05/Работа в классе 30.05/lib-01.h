//
//  lib-01.h
//  Работа в классе 30.05
//
//  Created by Станислав Егоров on 29.05.2024.
//

#pragma once
#include"Logger.h"
#include<iostream>
using namespace std;
class Lib01
{
    Logger* logger;
public:
    Lib01() { logger = Logger::getLogger(); }
    void Print() {
        logger->info("this is the info Print method of the lib01 class\n");
        logger->debug("this is the debug Print method of the lib01 class\n");
    }
    void LoggerAddress() { cout << "logger address: " << Logger::getLogger() << endl; }
};
