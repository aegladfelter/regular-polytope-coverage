#ifndef _OPTION_CONTAINER_GUARD_
#define _OPTION_CONTAINER_GUARD_

#include<vector>
#include<string>

class OptionContainer
{

private:
  // continers to hold different data types that keys in the config
  // file might be set to
  std::vector<std::pair<std::string, int>> _intOptions;
  std::vector<std::pair<std::string, bool>> _boolOptions;
  std::vector<std::pair<std::string, std::string>> _stringOptions;

  // is value is an int?
  bool isInt(const std::string& value) const;

  // is value a bool?
  bool isBool(const std::string& value) const;

  // is value a string?
  bool isString(const std::string& value);

  // convert a string to a bool
  bool evalBool(const std::string& value) const;

  // does the key exist in any container?
  // CTA: unusued
  // bool key_exists(const std::string& key) const;

public:

  // constructor
  OptionContainer();

  // push a value to the correct container
  bool push(const std::string& key,const std::string& value);

  // pull a key's int value
  int pull(const std::string& key, const int value) const;

  // pull a key's bool value
  bool pull(const std::string& key, const bool value) const;

  // pull a key's string value
  std::string pull(const std::string& key, const std::string& value) const;

};

#endif
