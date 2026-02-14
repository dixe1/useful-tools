//
// Created by bartek on 2/13/26.
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


class ConfigLoader
{
public:

    static std::unordered_map<std::string, std::string>
    load(const std::string& pathAndFileName)
    {
        std::unordered_map<std::string,std::string> config;

        std::fstream file(pathAndFileName, std::ios::in);
        checkFile(file);

        std::string line;
        while (std::getline(file, line))
        {
            size_t pos = line.find('=');

            if (pos == std::string::npos)
                continue;

            std::string key  = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            deleteSpaces(value);
            deleteSpaces(key);

            config[key] = value;
        }

        file.close();
        return config;
    }


private:

    // Helper functions
    static void checkFile(const std::fstream& file)
    {
        if (!file.is_open())
            throw std::runtime_error("Error opening file");

        if (!file.good())
            throw std::runtime_error("Error file not good");
    }
    static void deleteSpaces(std::string& line)
    {
        if (line.empty())
            return;

        if (line.at(line.length()-1) == ' ')
            line.erase(line.length()-1, line.length());

        if (line.at(0) == ' ')
            line.erase(0, 1);
    }
};