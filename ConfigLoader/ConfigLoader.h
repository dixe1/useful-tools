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
    static std::unordered_map<std::string, std::string> load(const std::string& pathAndFileName)
    {
        std::unordered_map<std::string,std::string> config;

        std::fstream file(pathAndFileName, std::ios::in);
        if (!file.is_open())
            std::cerr << "Error opening file" << std::endl;

        if (!file.good())
            std::cerr << "Error file not good" << std::endl;

        std::string line;
        while (std::getline(file, line))
        {
            size_t pos = line.find('=');

            if (pos == std::string::npos)
                continue;

            std::string key  = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            config[key] = value;
        }

        file.close();
        return config;
    }

};