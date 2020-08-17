

#include"Config.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<utility>
#include<algorithm>

Config* Config::_instance = nullptr;

Config::Config() {}


void Config::cleanUp()
{
    if (_instance != nullptr) delete _instance;
    _instance = nullptr;
}

bool Config::initialize(int argc, const char** cmdparams)
{
    // if an instance already exists, do not reinitialize
    if (_instance != nullptr) return false;

    // ensure atleast one command line argument was provided
    if (argc <= 1)
    {
        std::cerr << "Configuration file required" << std::endl;
        system("pause");
        return false;
    }

    // create a new instance of Config
    Config::_instance = new Config{};

    // extract first parameter from cmd parameters and store it as a string
    std::string cfg_file_name = cmdparams[1];

    // parse the file path
    return _instance->parse(cfg_file_name);
}

// return the instance of Config
Config* Config::getInstance()
{
    if (_instance == nullptr) std::cerr << "Configuration unitialized; returning null...whoops" << std::endl;

    return _instance;
}

// parse config file, provide path to this file
bool Config::parse(std::string& cfg_file_path) {
    // open the configuration file
    std::ifstream cfg(cfg_file_path);

    // if there is a problem finding the configuration file, print an
    // error and return false
    if (!cfg) {
        std::cerr << "Could not find configuration file:\t" << cfg_file_path << std::endl;
        return false;
    }


    std::string key, value, line;

    while (getline(cfg, line)) {
        // if the line is not a comment
        // and contains '=', push the attribute to OptionContainer
        if (line[0] != '#' && line.find('=') != std::string::npos) {

            // store the characters from the beginning of the line to the '=' character
            key = line.substr(0, line.find("="));

            // store characters from '=' to the end of the line
            value = line.substr(line.find("=") + 1);

            // strip key,value of white space
            key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
            value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());

            // create a new key value pair to store in the OptionContiner
            std::pair<std::string, std::string> new_option = std::make_pair(key, value);

            // push the pair into OptionContainer
            push(key, value);
        }
    }

    // close the configuration file
    cfg.close();

    // if the key value pairs in the configuration file
    // were stored correctly, return true
    return true;
}
