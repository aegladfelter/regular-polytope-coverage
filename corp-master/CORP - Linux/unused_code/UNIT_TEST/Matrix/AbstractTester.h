#ifndef _ABSTRACT_TESTER_H
#define _ABSTRACT_TESTER_H 1

#include <iostream>
#include <iostream>
#include <map>
#include <random>
#include <string>

class AbstractTester
{

protected:
	std::map<std::string, int>			_errorCountMap;
	std::string							_name;
	std::ostream&						_os;

public:
	AbstractTester(const std::string& name = "", std::ostream& out = std::cout)
		: _errorCountMap{}, _name{ name }, _os{ out }
	{
	}

	virtual ~AbstractTester()
	{
		_errorCountMap.clear();
	}


	//Pure virtual "run every test" function
	virtual void runAll() = 0;

	//Reports the results of the tests
	virtual void report()
	{

	}

	virtual void clear();

};





#endif 