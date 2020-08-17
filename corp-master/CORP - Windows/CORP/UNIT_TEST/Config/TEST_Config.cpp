#include"CppUnitTest.h"
#include"../../CORP/OptionContainer/OptionContainer.h"
#include"../../CORP/Config/Config.h"
#include<iostream>
#include<fstream>
#include"../OptionContainer/TEST_OptionContainer.cpp"

// generate a random config file
bool generateTestConfigFile(std::string fileToUse, std::vector<std::string>& keys) {
	
	// create ofstream object
	std::ofstream cfg(fileToUse);
	if (!cfg) {
		Logger::WriteMessage("File could not be opened");
		return false;
	}

	// write int keys
	for (int i = 0; i < keys.size()/3; i++) {
		cfg << keys.at(i) + "=" + "1";
	}

	// write bool keys
	for (int i = keys.size() / 3; i < (2.0/3) * keys.size() ; i++) {
		cfg << keys.at(i) + "=" + "true";
	}

	// close config
	cfg.close();
	
	return true;
}

bool readTestConfigFile(std::string fileToUse, std::vector<std::string> keys) {
	// simulate command line arguments
	int argc = 1;
	char const *argv[2];
	argv[0] = "main.cpp";
	argv[1] = fileToUse.c_str();
	generateTestConfigFile(argv[1],keys);
	Config::initialize(argc, argv);
	return true;
}

// ensure all values are as they should be
bool checkValues(std::string fileToUse,int keysToUse) {
	TestOptionsContainerHelper test_options_container_helper;
	bool result = true;

	std::vector<std::string> keys = test_options_container_helper.getKeyVector(keysToUse);
	if (!generateTestConfigFile(fileToUse, keys)) {
		Logger::WriteMessage("Generating test configuration file failed");
		return false;
	}
	if (!readTestConfigFile(fileToUse, keys)) {
		Logger::WriteMessage("Reading test configuration file failed");
		return false;
	}
	// check int values
	for (int i = 0; i < keys.size() / 3;i++) {
		if (Config::getInstance()->pull(keys.at(i), "0") != 1) {
			Logger::WriteMessage("Checking int values failed");
			result = false;
		}
	}

	// check bool values
	for (int i = keys.size() / 3; i < keys.size() * (2.0/3); i++) {
		if (Config::getInstance()->pull(keys.at(i), "false") != true) {
			Logger::WriteMessage("Checking bool values failed");
			result = false;
		}
	}

	return result;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CORP
{		
	TEST_CLASS(Config)
	{
	public:

		TEST_METHOD(parse)
		{
			Assert::AreEqual(true,::checkValues("test_config.txt",10));
		}

	};
}