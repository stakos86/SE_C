//
//  lib-02.h
//  Работа в классе 30.05
//
//  Created by Станислав Егоров on 29.05.2024.
//

#pragma once
#include"Logger.h"
#include<iostream>
using namespace std;
class Lib02
{
    Logger* logger;
public:
    Lib02() { logger = Logger::getLogger(); }
    void Print() {
        logger->info("this is the info Print method of the lib02 class\n");
        logger->debug("this is the debug Print method of the lib02 class\n");
    }
    void LoggerAddress() { cout << "logger address: " << Logger::getLogger() << endl; }
};
