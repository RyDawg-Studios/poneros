#pragma once

#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream

const char* read_from_file(const char* pathToFile)
{
    std::string content;
    std::ifstream fileStream(pathToFile, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << pathToFile << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    
    return content.c_str();
}
