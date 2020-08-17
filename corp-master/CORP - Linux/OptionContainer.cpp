
#include"OptionContainer.h"
#include<iostream>
#include<cstring>
#include<utility>


// constructor
OptionContainer::OptionContainer() {}

// return if value is an int or not
bool OptionContainer::isInt(const std::string& value) const {
	return !(std::atoi(value.c_str()) == 0 && value != "0");
}

// return if value is a bool or not
bool OptionContainer::isBool(const std::string& value) const {
  return  value == "false" || value == "true";
}

// convert a string to a bool
bool OptionContainer::evalBool(const std::string& value) const {
	return value == "true";
}

bool OptionContainer::isString(const std::string& value) {
	return !isBool(value) && !isInt(value);
}

// push a value to the correct container
bool OptionContainer::push(const std::string& key,const std::string& value) {

  // if value is an int, push it to the int container
  if(isInt(value)) {
      // create pair
      std::pair<std::string, int> new_option = std::make_pair(key, std::atoi(value.c_str()));

      // push to int_options
      _intOptions.push_back(new_option);

      return true;
  }

  // if value is a bool, push it the bool container
  else if(isBool(value)) {

    std::pair<std::string, int> new_option = std::make_pair(key, evalBool(value));

    _boolOptions.push_back(new_option);

    return true;
  }

  // if value is a string, push it to the string container
  else if(isString(value)) {

    std::pair<std::string, std::string> new_option = std::make_pair(key, value);

    _stringOptions.push_back(new_option);

    return true;
  }

  return false;
}

// pull a key's int value
int OptionContainer::pull(const std::string& key, const int value) const
{
  for(auto pair : _intOptions) {

    if(std::strcmp(std::get<0>(pair).c_str(), key.c_str()) == 0) {
      return std::get<1>(pair);
    }
  }
  return value;
}

// pull a key's bool value
bool OptionContainer::pull(const std::string& key, const bool value) const {

  for(auto pair : _boolOptions) {

    if(std::strcmp(std::get<0>(pair).c_str(), key.c_str()) == 0) {
      return std::get<1>(pair);
    }
  }
  return value;
}

// pull a key's string value 
std::string OptionContainer::pull(const std::string& key,
  const std::string& value) const {

    for(auto pair : _stringOptions) {

      if(std::strcmp(std::get<0>(pair).c_str(), key.c_str()) == 0) {
        return std::get<1>(pair);
      }
    }
    return value;
}
