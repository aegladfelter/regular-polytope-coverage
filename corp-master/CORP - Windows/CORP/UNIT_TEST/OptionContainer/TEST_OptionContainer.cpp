
#include"CppUnitTest.h"
#include"../../CORP/OptionContainer/OptionContainer.h"
#include<iostream>

class TestOptionsContainerHelper {
public:
	bool insertRandomSpace(std::string& input) {
		if (input.length() == 0) { return false; }
		input[rand() % input.length()] = ' ';
		return true;
	}

	std::string generateRandomKey() {
		char randomChar;
		std::string key = "";

		for (int i = 0; i < rand() % 100 + 1; i++) {
			key += (rand() % 26 + 97);
			insertRandomSpace(key);
		}
		return key;
	}

	std::vector<std::string> getKeyVector(int keysToGenerate) {
		std::vector<std::string> keys;

		for (int i = 0; i < keysToGenerate; i++) {
			keys.push_back(generateRandomKey());
		}
		return keys;
	}

	OptionContainer pushKeys(std::vector<std::string> keys) {
		OptionContainer container;

		// push ints
		for (int i = 0; i < keys.size() / 3.0; i++) {
			container.push(keys.at(i), "1");
		}

		// push bools
		for (int i = keys.size() / 3.0; i < keys.size() * (2.0 / 3.0); i++) {
			container.push(keys.at(i), "true");
		}
		return container;
	}

	bool pullKeys(std::vector<std::string> keys, OptionContainer &container) {

		bool result = false;

		// pull ints
		for (int i = 0; i < keys.size() / 3.0; i++) {
			if (container.pull(keys.at(i), 0) == 1) result = true;
		}

		//pull bools
		for (int i = keys.size() / 3.0; i < keys.size() * (2.0 / 3.0); i++) {
			if (container.pull(keys.at(i), false) == true) result = true;
		}

		return result;

	}

	bool pushPullTest(int keysToPush) {
		std::vector<std::string> keys = getKeyVector(keysToPush);

		return pullKeys(keys, pushKeys(keys));
	}
};

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CORP
{		
	TEST_CLASS(OptionContainer)
	{
	public:

		TEST_METHOD(pull)
		{
			TestOptionsContainerHelper test_options_container_helper;
			Assert::AreEqual(true,test_options_container_helper.pushPullTest(100));
		}

	};
}