#ifndef _CONFIG_GUARD
#define _CONFIG_GUARD

#include"OptionContainer.h"
#include<string.h>



class Config : public OptionContainer
{

private:
  // consturctor to be used by initialize()
  Config();

  // parse config file
  bool parse(std::string& cfg_file_name);


protected:
  // return the instance of Config
  static Config* _instance;

public:
  // return the instance of Config
  static Config* getInstance();

  // initialize an instance of Config
  static bool initialize(int argc, const char**);

  // CTA: added to delete the singleton; no way to invoke destructor.
  static void cleanUp();
};

#endif
